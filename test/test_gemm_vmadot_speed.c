#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "blis.h"



int main() {
    bli_init();

    char * filename = "blis_performance_results_4_acc.csv";
    FILE* csv_file = fopen(filename, "w");
    if (csv_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        exit(1);
    }
  
    cntx_t* cntx = bli_gks_query_cntx();
    obj_t a, b, c;
    obj_t alpha, beta;
    num_t dt = BLIS_FLOAT;
   
    bli_obj_create(dt, 1, 1, 0, 0, &alpha);
    bli_obj_create(dt, 1, 1, 0, 0, &beta);

    // Set up scalar multipliers (alpha = 1.0, beta = 0.0)
    bli_setsc(2.0f, 0.0, &alpha); 
    bli_setsc(1.2f, 0.0, &beta);  

    // Print CSV Header to stdout
    fprintf(csv_file, "M,NC,MC,KC,Time_Sec,GFLOPS\n");
    fflush(csv_file);
    // Define the parameter ranges for the sweep
    dim_t m_start = 128, m_end = 4096,  m_step = 128;
    dim_t kc_start = 128,  kc_end = 2048,   kc_step = 128;
    dim_t mc_start = 128,  mc_end = 768,  mc_step = 64;
    dim_t nc_start = 8192,  nc_end = 8192,  nc_step = 1024, nc=1024;

    //printf("Done init. Proceed with loop...\n");
    // Nested parametric sweep loops
    for(dim_t m = m_start; m <= m_end; m *= 2 ){
    //for (dim_t nc = nc_start; nc <= nc_end; nc += nc_step) {
        for (dim_t kc = kc_start; kc <= kc_end && kc <= m; kc += kc_step) {
            for (dim_t mc = mc_start; mc <= mc_end && mc <= m; mc += mc_step) {
            
                bli_obj_create(BLIS_HALF, m, m, 0, 0, &a);
                bli_obj_create(BLIS_HALF, m, m, 0, 0, &b);
                bli_obj_create(dt, m, m, 0, 0, &c);
                // Re-randomize / clear data matrices between runs
                bli_randm(&a);
                bli_randm(&b);
                bli_setm(&BLIS_ZERO, &c);
                
		        blksz_t my_kc;
                blksz_t my_mc;
                blksz_t my_nc;
                
		        bli_blksz_init_easy( &my_mc, mc, mc, mc, mc, mc, mc );
                bli_blksz_init_easy( &my_kc, kc, kc, kc, kc, kc, kc );
                bli_blksz_init_easy( &my_nc, nc, nc, nc, nc, nc, nc );

                bli_cntx_set_blksz( BLIS_NC, &my_nc, 0, cntx );
                bli_cntx_set_blksz( BLIS_MC, &my_mc, 0, cntx );
		        bli_cntx_set_blksz( BLIS_KC, &my_kc, 0, cntx );

                // Benchmark the specific execution window
    		    bli_obj_set_comp_prec( BLIS_HALF_PREC, &c );
                double start_time = bli_clock();
                bli_gemm_ex(&alpha, &a, &b, &beta, &c, cntx, NULL);
                double end_time = bli_clock();
                
                double total_flops = 2.0 * (double)m * (double)m * (double)m;
                double elapsed_time = end_time - start_time;
                double gflops = total_flops / (elapsed_time * 1.0e9);

                // Write metrics to the CSV file descriptor instead of stdout
                //fprintf(csv_file, "%ld,%ld,%ld,%ld,%.6f,%.2f\n", 
                        //m,(long)nc,(long)mc, (long)kc, elapsed_time, gflops);
                fprintf(stdout, "%ld,%ld,%ld,%ld,%.6f,%.2f\n", 
                        m,(long)nc,(long)mc, (long)kc, elapsed_time, gflops);

                fflush(stdout);
                
                // Force flush ensures that data isn't lost if the process hangs/crashes
                fflush(csv_file);
                bli_obj_free(&a);
                bli_obj_free(&b);
                bli_obj_free(&c);
            }
            //printf("Completed %.1f %%\n",(100.0*m)/(100.0*m_end));
            //printf("\n");
        }
    }
    // Safely close the file stream
    fclose(csv_file);
    
//}
    bli_finalize();
    return 0;
}
