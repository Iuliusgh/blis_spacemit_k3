#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "blis.h"

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

    bli_obj_create( dt, 1, 1, 0, 0, &alpha );
	bli_obj_create( dt, 1, 1, 0, 0, &beta );

    //alpha = BLIS_ONE;
    //beta  = BLIS_ZERO;
    
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
    
    
/*
    for (dim_t i = 0; i < m; i++)
        for (dim_t p = 0; p < k; p++)
            buf_a[i * rs_a + p * cs_a] = (_Float16)(i * k + p + 1);

    for (dim_t p = 0; p < k; p++)
        for (dim_t j = 0; j < n; j++)
            buf_b[p * rs_b + j * cs_b] = (_Float16)(j * k + p + 1);
*/


    // 3. Execute your CUSTOM implementation
    //printf("[DEBUG] Running custom gemm.\n");
    //bli_printm("Matrix A (Input):", &a, "% 6.1f", "");
    //bli_printm("Matrix B (Input):", &b, "% 6.1f", "");
    //bli_printm("Matrix C Reference: ", &c_generic, "%8.1f","");
    //printf(" alpha %f and beta %f...\n", (float)  alpha_val, (float) beta_val);
    bli_obj_set_comp_prec( BLIS_HALF_PREC, &c_custom );
    bli_gemm(&alpha, &a, &b, &beta, &c_custom);
    //printf("[DEBUG] CUSTOM bli_gemm finished without crashing.\n");
    bli_getsc(&alpha, &alpha_val, &dummy);
    bli_getsc(&beta,  &beta_val,  &dummy);  
    // 5. Run a pure C reference loop
    for (dim_t i = 0; i < m; i++) {
        for (dim_t j = 0; j < n; j++) {
            float sum = 0.0f;
            for (dim_t p = 0; p < k; p++) {
                sum += (float) (buf_a[i * rs_a + p * cs_a]  *  buf_b[p * rs_b + j * cs_b]);
            }
            float ab = sum * (float)alpha_val;
            buf_gen[i * rs_gen + j * cs_gen] =  fmaf((float)beta_val,buf_gen[i * rs_gen + j * cs_gen],ab) ; 
        }
    }
    // 6. Compare results element-by-element
    float threshold = 1e-2f; 
    float max_diff = 0.0f;
    int failed = 0;

    for (dim_t i = 0; i < m; i++) {
        for (dim_t j = 0; j < n; j++) {
            float val_cust =  buf_cust[i * rs_cust + j * cs_cust];
            float val_gen  =  buf_gen[i * rs_gen + j * cs_gen];
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
                    printf("%f ",(float) buf_gen[i*rs_cust + index * cs_cust]);
                }
                printf("\n");
                printf("Custom row %ld:\n",i);
                for (int index = 0; index < n; index++){
                    printf("%f ", (float) buf_cust[i * rs_cust + index * cs_cust]);
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
    bli_obj_free(&alpha); 
    bli_obj_free(&beta);

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

int main() {
    bli_init();

    int failures = run_test_suite(2048);
    //verify_custom_gemm(2048,2048,2048);
    //for(int i = 128 ; i<=2048 ; i+=128){
    //verify_custom_gemm(i,i,i);
    //}
    //verify_custom_gemm(65,66,65);
    //verify_custom_gemm(65,65,66);


    bli_finalize();
    return 0;
}
