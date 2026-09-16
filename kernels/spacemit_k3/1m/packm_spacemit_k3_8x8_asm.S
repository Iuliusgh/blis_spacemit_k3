	.text
	.balign 4
	.global packm_spacemit_k3_8x8_asm
# RV64IDV system
# Function Signature:
# void packm_spacemit_k3_8x8_asm(size_t dim, size_t k, inc_t inca, inc_t lda, const _Float16* M_addr, _Float16* M_pack)
#define Dim a0
#define K a1
#define inca a2
#define lda a3
#define M_addr a4
#define M_pack a5

packm_spacemit_k3_8x8_asm:
    slli t6, lda, 2             #Leading dimension in bytes
    slli t5, inca, 2            #inca in bytes
    li t0, 8                    
    beq Dim, t0, K_loop_8      
    addi t0, t0, -1
    beq Dim, t0, K_loop_7      
    addi t0, t0, -1
    beq Dim, t0, K_loop_6      
    addi t0, t0, -1
    beq Dim, t0, K_loop_5      
    addi t0, t0, -1                                            
    beq Dim, t0, K_loop_4
    addi t0, t0, -1
    beq Dim, t0, K_loop_3      
    addi t0, t0, -1              
    beq Dim, t0, K_loop_2      
    j K_loop_1        
K_loop_8:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m4      #VL = min(K,256)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v4, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v8, (t2), t6       #load row 3
    add t2, t2, t5              #point row 4
    vlse16.v v12, (t2), t6      #load row 4
    add t2, t2, t5              #point row 5
    vlse16.v v16, (t2), t6      #load row 5
    add t2, t2, t5              #point row 6
    vlse16.v v20, (t2), t6      #load row 6                
    add t2, t2, t5              #point row 7
    vlse16.v v24, (t2), t6      #load row 7
    add t2, t2, t5              #point row 8
    vlse16.v v28, (t2), t6      #load row 8
    sub K, K, t0                #K - VL remaining elements
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v4, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[2][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[3][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v16, (M_pack)       #[4][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v20, (M_pack)       #[5][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes         
    vse16.v v24, (M_pack)       #[6][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v28, (M_pack)       #[7][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v5, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[2][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[3][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v17, (M_pack)       #[4][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v21, (M_pack)       #[5][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v25, (M_pack)       #[6][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v29, (M_pack)       #[7][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v6, (M_pack)        #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[2][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[3][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v18, (M_pack)       #[4][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v22, (M_pack)       #[5][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v26, (M_pack)       #[6][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v30, (M_pack)       #[7][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v7, (M_pack)        #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[2][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[3][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v19, (M_pack)       #[4][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v23, (M_pack)       #[5][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v27, (M_pack)       #[6][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v31, (M_pack)       #[7][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    bgtz K, K_loop_8            #loop back if K > 0
    j End
K_loop_7:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m4      #VL = min(K,128)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v4, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v8, (t2), t6       #load row 3
    add t2, t2, t5              #point row 4
    vlse16.v v12, (t2), t6      #load row 4
    add t2, t2, t5              #point row 5
    vlse16.v v16, (t2), t6      #load row 5
    add t2, t2, t5              #point row 6
    vlse16.v v20, (t2), t6      #load row 6                
    add t2, t2, t5              #point row 7
    vlse16.v v24, (t2), t6      #load row 7
    sub K, K, t0                #K - VL remaining elements
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v4, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[2][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[3][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v16, (M_pack)       #[4][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v20, (M_pack)       #[5][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes         
    vse16.v v24, (M_pack)       #[6][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v5, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[2][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[3][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v17, (M_pack)       #[4][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v21, (M_pack)       #[5][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v25, (M_pack)       #[6][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v6, (M_pack)        #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[2][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[3][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v18, (M_pack)       #[4][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v22, (M_pack)       #[5][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v26, (M_pack)       #[6][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v7, (M_pack)        #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[2][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[3][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v19, (M_pack)       #[4][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v23, (M_pack)       #[5][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v27, (M_pack)       #[6][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    bgtz K, K_loop_7            #loop back if K > 0
    j End
K_loop_6:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m4      #VL = min(K,128)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v4, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v8, (t2), t6       #load row 3
    add t2, t2, t5              #point row 4
    vlse16.v v12, (t2), t6      #load row 4
    add t2, t2, t5              #point row 5
    vlse16.v v16, (t2), t6      #load row 5
    add t2, t2, t5              #point row 6
    vlse16.v v20, (t2), t6      #load row 6                
    sub K, K, t0                #K - VL remaining elements
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v4, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[2][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[3][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v16, (M_pack)       #[4][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v20, (M_pack)       #[5][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes         
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v5, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[2][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[3][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v17, (M_pack)       #[4][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v21, (M_pack)       #[5][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v6, (M_pack)        #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[2][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[3][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v18, (M_pack)       #[4][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v22, (M_pack)       #[5][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v7, (M_pack)        #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[2][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[3][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v19, (M_pack)       #[4][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    vse16.v v23, (M_pack)       #[5][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    bgtz K, K_loop_6            #loop back if K > 0
    j End
K_loop_5:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m4      #VL = min(K,128)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v4, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v8, (t2), t6       #load row 3
    add t2, t2, t5              #point row 4
    vlse16.v v12, (t2), t6      #load row 4
    add t2, t2, t5              #point row 5
    vlse16.v v16, (t2), t6      #load row 5
    sub K, K, t0                #K - VL remaining elements
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v4, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[2][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[3][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v16, (M_pack)       #[4][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v5, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[2][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[3][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v17, (M_pack)       #[4][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v6, (M_pack)        #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[2][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[3][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v18, (M_pack)       #[4][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v7, (M_pack)        #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[2][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[3][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes           
    vse16.v v19, (M_pack)       #[4][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes        
    bgtz K, K_loop_5            #loop back if K > 0
    j End
K_loop_4:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v8, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v16, (t2), t6      #load row 3
    add t2, t2, t5              #point row 4
    vlse16.v v24, (t2), t6      #load row 4
    sub K, K, t0                #K counter -= VL
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v16, (M_pack)       #[2][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v24, (M_pack)       #[3][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v17, (M_pack)       #[2][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v25, (M_pack)       #[3][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v18, (M_pack)       #[2][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v26, (M_pack)       #[3][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v19, (M_pack)       #[2][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v27, (M_pack)       #[3][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v4, (M_pack)        #[0][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[1][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v20, (M_pack)       #[2][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v28, (M_pack)       #[3][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v5, (M_pack)        #[0][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[1][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v21, (M_pack)       #[2][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v29, (M_pack)       #[3][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v6, (M_pack)        #[0][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[1][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v22, (M_pack)       #[2][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v30, (M_pack)       #[3][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v7, (M_pack)        #[0][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[1][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v23, (M_pack)       #[2][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v31, (M_pack)       #[3][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    bgtz K, K_loop_3            #loop back if K > 0
    j End
K_loop_3:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v8, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v16, (t2), t6      #load row 3
    add t2, t2, t5              #point row 4
    vlse16.v v24, (t2), t6      #load row 4
    sub K, K, t0                #K counter -= VL
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v16, (M_pack)       #[2][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v17, (M_pack)       #[2][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v18, (M_pack)       #[2][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v19, (M_pack)       #[2][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v4, (M_pack)        #[0][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[1][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v20, (M_pack)       #[2][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v5, (M_pack)        #[0][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[1][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v21, (M_pack)       #[2][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v6, (M_pack)        #[0][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[1][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v22, (M_pack)       #[2][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v7, (M_pack)        #[0][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[1][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v23, (M_pack)       #[2][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    bgtz K, K_loop_3            #loop back if K > 0
    j End
K_loop_2:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v0, (M_addr), t6   #load row 0 first chunk
    add t2, M_addr, t5          #row 1 address
    vlse16.v v8, (t2), t6       #load row 1 first chunk
    sub K, K, t0                #K counter -= VL
    mul t1, t0, t6
    add M_addr, M_addr, t1
    sh2add t2, t0, t2           #row 1 second chunk offset
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v0, (M_pack)        #[0][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v8, (M_pack)        #[1][0-31]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v1, (M_pack)        #[0][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v9, (M_pack)        #[1][32-63]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v2, (M_pack)        #[0][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v10, (M_pack)       #[1][64-95]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v3, (M_pack)        #[0][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v11, (M_pack)       #[1][96-127]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v4, (M_pack)        #[0][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v12, (M_pack)       #[1][128-159]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v5, (M_pack)        #[0][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v13, (M_pack)       #[1][160-191]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v6, (M_pack)        #[0][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v14, (M_pack)       #[1][192-223]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v7, (M_pack)        #[0][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v15, (M_pack)       #[1][224-255]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    #SECOND CHUNK
    vsetvli t0, K, e16, m8      #VL = min(K,256), avoid reading out of bounds
    vlse16.v v16, (M_addr), t6  #load row 0 second chunk
    add t2, M_addr, t5          #row 1 address
    vlse16.v v24, (t2), t6      #load row 1 second chunk
    sub K, K, t0                #K counter -= VL
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v16, (M_pack)       #[0][256-287]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v24, (M_pack)       #[1][256-287]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v17, (M_pack)       #[0][288-319]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v25, (M_pack)       #[1][288-319]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v18, (M_pack)       #[0][320-351]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v26, (M_pack)       #[1][320-351]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v19, (M_pack)       #[0][352-383]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v27, (M_pack)       #[1][352-383]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v20, (M_pack)       #[0][384-415]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v28, (M_pack)       #[1][384-415]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v21, (M_pack)       #[0][416-447]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v29, (M_pack)       #[1][416-447]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v22, (M_pack)       #[0][448-479]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v30, (M_pack)       #[1][448-479]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    vsetvli t3, t0, e16, m1     #VL = min(t0,32)
    vse16.v v23, (M_pack)       #[0][480-511]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    vse16.v v31, (M_pack)       #[1][480-511]
    sh2add M_pack, t3, M_pack   #advance pointer stored elements bytes
    sub t0, t0, t3              #subtract processed elements from total
    bgtz K, K_loop_2            #loop back if K > 0
    j End
K_loop_1:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               # reset
    vmv.v.i v16, 0              # reset
    vmv.v.i v24, 0              # reset
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v0, (M_addr), t6   #load first row
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v0, (M_pack)        #[0][0-255]
    sh2add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v8, (M_addr), t6   #load next row chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v8, (M_pack)        #[0][256-511]
    sh2add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v16, (M_addr), t6  #load next row chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v16, (M_pack)       #[0][512-767]
    sh2add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v24, (M_addr), t6  #load next row chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v24, (M_pack)       #[0][768-1024]
    sh2add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    bgtz K, K_loop_1            #loop back if K > 0
End:
    ret
