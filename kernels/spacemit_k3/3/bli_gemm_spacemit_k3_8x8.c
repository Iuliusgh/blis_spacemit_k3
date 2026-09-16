#include "blis.h"
#include "stdio.h"
extern void gemm_spacemit_k3_8x8_asm(dim_t m, dim_t n, dim_t k, const _Float16* A, const _Float16* B, float * C,int rs_c, int cs_c, float alpha, float beta);

void bli_sgemm_spacemit_k3_8x8
     (
             dim_t      m,
             dim_t      n,
             dim_t      k,
       const void*      alpha,
       const void*      a,
       const void*      b,
       const void*      beta,
             void*      c, inc_t rs_c, inc_t cs_c,
       const auxinfo_t* data,
       const cntx_t*    cntx
     )
     {
        printf("Using custom sgemm with alpha %f and beta %f...\n", bli_obj_buffer(alpha), *(float *) beta);
        gemm_spacemit_k3_8x8_asm(m,n,k, a, b,c,rs_c,cs_c,*(float *) beta, *(float *) beta);
     }
