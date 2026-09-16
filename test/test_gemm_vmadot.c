#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "blis.h"

void save_array_text_scalar(const char* filename, const float* array, int m, int n) {
    // Open the file in "w" mode (write text)
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    // Loop and write each element on a new line
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            // Use standard formatting. "%f" or "%e" (scientific notation for floats)
            fprintf(fp, "% 6.1f ", array[i * n + j]); 
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}
void pack_scalar(float* a, float* a_pack, int m, int n, int rs, int cs){
    int idx=0;
    int i = 0, j = 0;
    if(rs == 1 && cs != 1){
       
        while(i < m){
            int h = m - i >= 8 ? 8 : m - i;
            while(j < n){
                int w = n - j >= 4 ? 4 : n - j;
                for(int k = 0; k < h; k++){
                    for(int l = 0; l < w; l++){
                       a_pack[idx]  =  a[(i + k) * rs + (j + l) * cs];
                       idx++;
                    }
                }
                j += w;
            }
            i += h;
        }
    }
    else if(rs != 1 && cs == 1){
        while(i < m){
            int h = m - i >= 4 ? 4 : m - i;
            while(j < n){
                int w = n - j >= 8 ? 8 : n - j;
                for(int k = 0; k < h; k++){
                    for(int l = 0; l < w; l++){
                       a_pack[idx]  =  a[(i + k) * cs + (j + l) * rs];
                       idx++;
                    }
                }
                j += w;
            }
            i += h;
        }
    }
}
int verify_custom_gemm(dim_t m, dim_t n, dim_t k) {
    obj_t a, b, c_custom, c_generic; 
    obj_t alpha, beta;
    double alpha_val, beta_val, dummy;
    num_t dt = BLIS_FLOAT; // Using 32-bit float

    // 1. Create BLIS objects
    bli_obj_create(BLIS_HALF, m, k, 0, 0, &a);
    bli_obj_create(BLIS_HALF, k, n, 0, 0, &b);
    bli_obj_create(dt, m, n, 0, 0, &c_custom);
    bli_obj_create(dt, m, n, 0, 0, &c_generic);

    bli_obj_create(dt, 1, 1, 0, 0, &alpha);
    bli_obj_create(dt, 1, 1, 0, 0, &beta);
    
    // 2. Initialize inputs identically (Alpha = 1.0, Beta = 0.0)
    bli_setsc(1.0f, 0.0, &alpha); 
    bli_setsc(0.0f, 0.0, &beta);
    
    
    // Fill A and B with small random integers (-1.0 to 1.0) for easier reading
    bli_randm(&a);
    bli_randm(&b);

    bli_setm(&BLIS_ZERO, &c_custom);
    bli_setm(&BLIS_ZERO, &c_generic);

    // 4. Extract pointers and strides
    _Float16* buf_a    = (_Float16*)bli_obj_buffer(&a);
    inc_t rs_a      = bli_obj_row_stride(&a);
    inc_t cs_a      = bli_obj_col_stride(&a);

    _Float16* buf_b    = (_Float16*)bli_obj_buffer(&b);
    inc_t rs_b      = bli_obj_row_stride(&b);
    inc_t cs_b      = bli_obj_col_stride(&b);

    float* buf_gen  = (float*)bli_obj_buffer(&c_generic);
    inc_t rs_gen    = bli_obj_row_stride(&c_generic);
    inc_t cs_gen    = bli_obj_col_stride(&c_generic);
    //printf("Using rs: %ld, cs: %ld in reference gemm\n",rs_gen, cs_gen);
    float* buf_cust = (float*)bli_obj_buffer(&c_custom);
    inc_t rs_cust   = bli_obj_row_stride(&c_custom);
    inc_t cs_cust   = bli_obj_col_stride(&c_custom);
    //printf("Using rs: %ld, cs: %ld in custom gemm\n",rs_cust, cs_cust);
    
    // 3. Execute your CUSTOM implementation
    //printf("[DEBUG] Running custom gemm.\n");
    //bli_printm("Matrix A (Input):", &a, "% 6.1f", "");
    //bli_printm("Matrix B (Input):", &b, "% 6.1f", "");
    //bli_printm("Matrix C Reference: ", &c_generic, "%8.1f","");
    //printf(" alpha %f and beta %f...\n", (float)  alpha_val, (float) beta_val);
    //bli_obj_set_comp_prec( BLIS_HALF_PREC, &c_custom );
    bli_gemm(&alpha, &a, &b, &beta, &c_custom);
    //printf("[DEBUG] CUSTOM bli_gemm finished without crashing.\n");
    bli_getsc(&alpha, &alpha_val, &dummy);
    bli_getsc(&beta,  &beta_val,  &dummy);  
    // 5. Run a pure C reference loop
    for (dim_t i = 0; i < m; i++) {
        for (dim_t j = 0; j < n; j++) {
            float sum = 0.0f;
            for (dim_t p = 0; p < k; p++) {
                float val_a = (float) buf_a[i * rs_a + p * cs_a];
                float val_b = (float) buf_b[p * rs_b + j * cs_b];
                sum += (float) val_a * val_b;
            }
            buf_gen[i * rs_gen + j * cs_gen] = sum * (float)alpha_val + buf_gen[i * rs_gen + j * cs_gen] * (float)beta_val; 
        }
    }
    // 6. Compare results element-by-element
    float threshold = 1e-4f; 
    float max_diff = 0.0f;
    int failed = 0;

    for (dim_t i = 0; i < m; i++) {
        for (dim_t j = 0; j < n; j++) {
            float val_cust = buf_cust[i * rs_cust + j * cs_cust];
            float val_gen  = buf_gen[i * rs_gen + j * cs_gen];
            float diff     = fabsf(val_cust - val_gen);

            if (diff > max_diff) {
                max_diff = diff;
            }

            // ONLY print on the very first failure of this matrix size
            if (diff > threshold && !failed) {
                printf("\n[\033[31mFAIL\033[0m] Mismatch detected at C[%ld][%ld] for size %ldx%ldx%ld\n", 
                       (long)i, (long)j, (long)m, (long)n, (long)k);
                printf("  Reference (Expected) = %f\n", val_gen);
                printf("  Custom (Got)         = %f\n\n", val_cust);
                /*
                printf("A row %ld:\n",i);
                for (int index = 0; index < n; index++){
                    printf("%3.1lf,",buf_a[i*rs_a + index * cs_a]);
                }
                printf("\n");
                printf("B col %ld:\n",i);
                for (int index = 0; index < n; index++){
                    printf("%3.1lf,",buf_b[i*rs_b + index * cs_b]);
                }
                printf("\n");*/
                printf("Reference row %ld:\n",i);
                for (int index = 0; index < n; index++){
                    printf("%8.1f ",buf_gen[i*rs_cust + index * cs_cust]);
                }
                printf("\n");
                printf("Custom row %ld:\n",i);
                for (int index = 0; index < n; index++){
                    printf("%8.1f ",buf_cust[i * rs_cust + index * cs_cust]);
                }
                printf("\n");
                // DUMP THE MATRICES
                //printf("\n--- RAW MEMORY DUMP (No Strides) ---\n");
                //bli_printm("Matrix A (Input):", &a, "%8.1f", "");
                //bli_printm("Matrix B (Input):", &b, "%8.1f", "");
                //bli_printm("Matrix C Reference: ", &c_generic, "%8.1f","");
                //bli_printm("Matrix C Custom: ", &c_custom, "%8.1f","");
                //printf("------------------------------------\n");

                failed = 1;
            }
        }
    }

    if (!failed) {
        printf("Size (%4ld x %4ld x %4ld) -> Max Diff: %10.3e [\033[32mPASS\033[0m]\n", 
               (long)m, (long)n, (long)k, max_diff);
    }

    //bli_printm("Matrix C Reference: ", &c_generic, "%8.1f","");
    //bli_printm("Matrix C Custom: ", &c_custom, "%8.1f","");

    // Free resources
    bli_obj_free(&a); bli_obj_free(&b);
    bli_obj_free(&c_custom); bli_obj_free(&c_generic);
    bli_obj_free(&alpha); bli_obj_free(&beta);

    return failed;
}
int run_test_suite(dim_t max_dim) {
    printf("========================================================================\n");
    printf("Testing Custom Kernel against Pure C Reference Loop (Sizes 1 to %ld)\n", (long)max_dim);
    printf("========================================================================\n");

    int total_failures = 0;

    // Loop through all sizes from 1 to max_dim
    for (dim_t dim = 1; dim <= max_dim; dim++) {
        
        // Print progress for small sizes, and every 64 steps for larger sizes
        if (dim <= 16 || dim % 64 == 0) {
            printf("--> Advancing to size: %ld x %ld x %ld\n", (long)dim, (long)dim, (long)dim);
            fflush(stdout);
        }

        // 1. Run the standard Square Matrix Verification (M = N = K)
        total_failures += verify_custom_gemm(dim, dim, dim);

        // HALT EARLY IF SQUARE TEST FAILS
        if (total_failures > 0) {
            printf("\n[\033[31mSTOP\033[0m] Testing halted at square size %ld due to mismatch.\n", (long)dim);
            break;
        }

        // 2. PRO-TIP: Run an Irregular Shape Verification (M != N != K) every 7th iteration
        if (dim % 7 == 0) {
            dim_t m = dim;
            dim_t n = (dim % 5) + 3;  // Keeps columns small, odd, and dynamic
            dim_t k = (dim % 3) + 1;  // Keeps dot-product reduction axis tight and irregular
            
            total_failures += verify_custom_gemm(m, n, k);
            
            // HALT EARLY IF IRREGULAR STRIDE TEST FAILS
            if (total_failures > 0) {
                printf("\n[\033[31mSTOP\033[0m] Testing halted at irregular size %ldx%ldx%ld due to mismatch.\n", 
                       (long)m, (long)n, (long)k);
                break;
            }
        }
    }

    printf("========================================================================\n");
    if (total_failures == 0) {
        printf("\033[32mALL TESTS (SQUARE & IRREGULAR) PASSED SUCCESSFULLY UP TO %ld!\033[0m\n", (long)max_dim);
    } else {
        printf("\033[31mTEST SUITE FAILED.\033[0m\n");
    }
    printf("========================================================================\n");

    return total_failures;
}
void run_block_size_sweep(){
    char * filename = "blis_performance_results.csv";
    FILE* csv_file = fopen(filename, "w");
    if (csv_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        return;
    }
    // Problem dimensions for the GEMM operation
    dim_t M = 2048;
    dim_t N = 2048;
    dim_t K = 2048;

    cntx_t* cntx = bli_gks_query_cntx();
    // Allocate matrices using the BLIS Object API (Double Precision)
    obj_t a, b, c;
    obj_t alpha, beta;
    num_t dt = BLIS_FLOAT;
    bli_obj_create(dt, M, K, 0, 0, &a);
    bli_obj_create(dt, K, N, 0, 0, &b);
    bli_obj_create(dt, M, N, 0, 0, &c);

    bli_obj_create(dt, 1, 1, 0, 0, &alpha);
    bli_obj_create(dt, 1, 1, 0, 0, &beta);

    // Set up scalar multipliers (alpha = 1.0, beta = 0.0)
    bli_setsc(1.0, 0.0, &alpha); 
    bli_setsc(0.0, 0.0, &beta);  

    // Calculate total theoretical floating-point operations (2 * M * N * K)
    double total_flops = 2.0 * (double)M * (double)N * (double)K;

    // Print CSV Header to stdout
    fprintf(csv_file, "NC,MC,KC,Time_Sec,GFLOPS\n");
    fflush(csv_file);
    // Define the parameter ranges for the sweep
    //dim_t nc_start = 64, nc_end = 4096,  nc_step = 64;
    dim_t mc_start = 256,  mc_end = 524288,  mc_step = 64;
    dim_t kc_start = 64,  kc_end = 32768,   kc_step = 64;

    // Run a quick warmup GEMM to ramp up CPU frequency scaling governor
    bli_randm(&a);bli_randm(&b);bli_setm(&BLIS_ZERO, &c);//bli_rand_int8m(&a); bli_rand_int8m(&b);bli_setm(&BLIS_ZERO, &c);
    bli_gemm_ex(&alpha, &a, &b, &beta, &c, cntx, NULL);

    // Nested parametric sweep loops
    //for (dim_t nc = nc_start; nc <= nc_end; nc += nc_step) {
        for (dim_t kc = kc_start; kc <= kc_end; kc += kc_step) {
            for (dim_t mc = kc_start; mc <= mc_end; mc += mc_step) {
            
                // Re-randomize / clear data matrices between runs
                bli_randm(&a);//bli_rand_int8m(&a);
                bli_randm(&b);//bli_rand_int8m(&b);
                bli_setm(&BLIS_ZERO, &c);
                
				blksz_t my_kc;
                blksz_t my_mc;
                //blksz_t my_nc;
                
				bli_blksz_init ( &my_mc,
							0, mc, 0, 0, 0, 0, 
							0, mc, 0, 0, 0, 0);
                bli_blksz_init ( &my_kc,
							0, kc, 0, 0, 0, 0, 
	                        0, kc, 0, 0, 0, 0);
                //bli_blksz_init ( &my_nc,
							//nc, 0, 0, 0, 
							//nc, 0, 0, 0);
                //bli_cntx_set_blksz( BLIS_NC, &my_nc, 0, cntx );
                bli_cntx_set_blksz( BLIS_MC, &my_mc, 0, cntx );
				bli_cntx_set_blksz( BLIS_KC, &my_kc, 0, cntx );

                // Benchmark the specific execution window
                double start_time = bli_clock();
                bli_gemm_ex(&alpha, &a, &b, &beta, &c, cntx, NULL);
                double end_time = bli_clock();
                
                double elapsed_time = end_time - start_time;
                double gflops = total_flops / (elapsed_time * 1.0e9);

                // Write metrics to the CSV file descriptor instead of stdout
                fprintf(csv_file, "%ld,%ld,%.6f,%.2f\n", 
                        (long)mc, (long)kc, elapsed_time, gflops);
                
                // Force flush ensures that data isn't lost if the process hangs/crashes
                fflush(csv_file);
            }
            printf("Completed %.1f %%\n",(100.0*kc)/(100.0*kc_end));
        }
    //}
    // Safely close the file stream
    fclose(csv_file);
    // Clean up allocated object memory inside the scope of the function
    bli_obj_free(&a);
    bli_obj_free(&b);
    bli_obj_free(&c);
}

int main() {
    bli_init();


    int failures = run_test_suite(200);
    //verify_custom_gemm(2048,2048,2048);
    //verify_custom_gemm(66,65,65);
    //verify_custom_gemm(65,66,65);
    //verify_custom_gemm(65,65,66);

    
    //printf("[DEBUG] Starting parameter sweep...\n");
    //run_block_size_sweep();
    //printf("[DEBUG] Sweep completed successfully.\n");

    bli_finalize();
    return 0;
}