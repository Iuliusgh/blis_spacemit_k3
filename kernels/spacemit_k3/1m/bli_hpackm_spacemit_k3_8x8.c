#include "blis.h"
#include "stdio.h"
extern void packm_spacemit_k3_8x8_asm(dim_t dim, dim_t k, inc_t inca, inc_t lda, const _Float16* M_address, _Float16* M_pack);

void bli_hpackm_spacemit_k3_8x8
     (
             conj_t  conja,
             pack_t  schema,
             dim_t   cdim0,
             dim_t   cdim_max,
             dim_t   cdim_bcast,
             dim_t   k0,
             dim_t   k0_max,
       const void*   kappa,
       const void*   a, inc_t inca0, inc_t lda0,
             void*   p,              inc_t ldp0,
       const void*   params,
       const cntx_t* cntx
     )
{     
      printf("Packing...\n lda: %ld, inca: %ld \n", lda0,inca0);

      packm_spacemit_k3_8x8_asm(cdim0, k0, inca0, lda0, a , p);
      /*
      if(lda0 != 1 && inca0 == 1){
            printf("Matrix b:\n");
            for(int i=0; i< k0; i++){
                  for(int j = 0; j < cdim0; j++){
                        printf("% 6.1f ", (double)((_Float16*)  a)[i * lda0 + j * inca0]);
                  }
                  printf("\n");
                  if((i+1) %8 == 0){printf("\n");}
            }
            printf("\n");
            printf("Matrix b_pack:\n");
            for(int i=0; i< cdim0; i++){
                  for(int j = 0; j < k0; j++){
                        printf("% 6.1f ", (double)((_Float16*)  p)[i * k0 + j]);
                        if((i * k0 + j+1 ) % 8 == 0 || (j + 1) == k0){printf("\t");}
                        if((i * k0 + j + 1) % (8*cdim0) == 0){printf("\n");}
                  }
                  //printf("\n");
            }
            printf("\n");
      }else if(lda0 == 1 && inca0 != 1){
            printf("Matrix a:\n");
            for(int i=0; i< cdim0; i++){
                  for(int j = 0; j < k0; j++){
                        printf("% 6.1f ", (double)((_Float16*)  a)[i * inca0 + j * lda0]);
                  }
                  printf("\n");
            }
            printf("\n");
            printf("Matrix a_pack:\n");
            for(int i=0; i< cdim0; i++){
                  for(int j = 0; j < k0; j++){
                        printf("% 6.1f ", (double)((_Float16*)  p)[i * k0 + j]);
                  }
                  printf("\n");
            }
            printf("\n");
      }
      */
}