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
    slli t6, lda, 1             #Leading dimension * element size (2 bytes/element)
    slli t5, inca, 1            #inca * element size (2 bytes/element)
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
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_8_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v4, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v8, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v12, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v16, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v20, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v24, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v28, (M_pack)       #[7][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v4, v4, t1    
    vslidedown.vx v8, v8, t1
    vslidedown.vx v12, v12, t1
    vslidedown.vx v16, v16, t1
    vslidedown.vx v20, v20, t1
    vslidedown.vx v24, v24, t1
    vslidedown.vx v28, v28, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_8_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_8_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v5, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v9, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v13, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v17, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v21, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v25, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v29, (M_pack)       #[7][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v5, v5, t1    
    vslidedown.vx v9, v9, t1
    vslidedown.vx v13, v13, t1
    vslidedown.vx v17, v17, t1
    vslidedown.vx v21, v21, t1
    vslidedown.vx v25, v25, t1
    vslidedown.vx v29, v29, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_8_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_8_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v6, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v10, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v14, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v18, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v22, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v26, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v30, (M_pack)       #[7][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v6, v6, t1
    vslidedown.vx v10, v10, t1    
    vslidedown.vx v14, v14, t1
    vslidedown.vx v18, v18, t1
    vslidedown.vx v22, v22, t1
    vslidedown.vx v26, v26, t1
    vslidedown.vx v30, v30, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_8_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_8_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v7, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v11, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v15, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v19, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v23, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v27, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v31, (M_pack)       #[7][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v7, v7, t1
    vslidedown.vx v11, v11, t1    
    vslidedown.vx v15, v15, t1
    vslidedown.vx v19, v19, t1
    vslidedown.vx v23, v23, t1
    vslidedown.vx v27, v27, t1
    vslidedown.vx v31, v31, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_8_4         #Loop back
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
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_7_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v4, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v8, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v12, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v16, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v20, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v24, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v4, v4, t1    
    vslidedown.vx v8, v8, t1
    vslidedown.vx v12, v12, t1
    vslidedown.vx v16, v16, t1
    vslidedown.vx v20, v20, t1
    vslidedown.vx v24, v24, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_7_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_7_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v5, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v9, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v13, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v17, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v21, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v25, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v5, v5, t1    
    vslidedown.vx v9, v9, t1
    vslidedown.vx v13, v13, t1
    vslidedown.vx v17, v17, t1
    vslidedown.vx v21, v21, t1
    vslidedown.vx v25, v25, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_7_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_7_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v6, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v10, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v14, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v18, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v22, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v26, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v6, v6, t1
    vslidedown.vx v10, v10, t1    
    vslidedown.vx v14, v14, t1
    vslidedown.vx v18, v18, t1
    vslidedown.vx v22, v22, t1
    vslidedown.vx v26, v26, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_7_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_7_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v7, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v11, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v15, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v19, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v23, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v27, (M_pack)       #[6][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v7, v7, t1
    vslidedown.vx v11, v11, t1    
    vslidedown.vx v15, v15, t1
    vslidedown.vx v19, v19, t1
    vslidedown.vx v23, v23, t1
    vslidedown.vx v27, v27, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_7_4         #Loop back
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
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_6_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v4, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v8, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v12, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v16, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v20, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v4, v4, t1    
    vslidedown.vx v8, v8, t1
    vslidedown.vx v12, v12, t1
    vslidedown.vx v16, v16, t1
    vslidedown.vx v20, v20, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_6_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_6_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v5, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v9, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v13, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v17, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v21, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v5, v5, t1    
    vslidedown.vx v9, v9, t1
    vslidedown.vx v13, v13, t1
    vslidedown.vx v17, v17, t1
    vslidedown.vx v21, v21, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_6_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_6_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v6, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v10, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v14, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v18, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v22, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v6, v6, t1
    vslidedown.vx v10, v10, t1    
    vslidedown.vx v14, v14, t1
    vslidedown.vx v18, v18, t1
    vslidedown.vx v22, v22, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_6_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_6_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v7, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v11, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v15, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v19, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v23, (M_pack)       #[5][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v7, v7, t1
    vslidedown.vx v11, v11, t1    
    vslidedown.vx v15, v15, t1
    vslidedown.vx v19, v19, t1
    vslidedown.vx v23, v23, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_6_4         #Loop back
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
    mul t1, t0, t6              #processed elements offset
    add M_addr, M_addr, t1      #advance source address
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_5_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v4, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v8, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v12, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v16, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v4, v4, t1    
    vslidedown.vx v8, v8, t1
    vslidedown.vx v12, v12, t1
    vslidedown.vx v16, v16, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_5_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_5_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v5, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v9, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v13, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v17, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v5, v5, t1    
    vslidedown.vx v9, v9, t1
    vslidedown.vx v13, v13, t1
    vslidedown.vx v17, v17, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_5_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_5_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v6, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v10, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v14, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v18, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v6, v6, t1
    vslidedown.vx v10, v10, t1    
    vslidedown.vx v14, v14, t1
    vslidedown.vx v18, v18, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_5_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_5_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v7, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v11, (M_pack)        #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v15, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v19, (M_pack)       #[4][0-7]
    sh1add M_pack, t1, M_pack
    vsetvli t2, K, e16, m1      #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v7, v7, t1
    vslidedown.vx v11, v11, t1    
    vslidedown.vx v15, v15, t1
    vslidedown.vx v19, v19, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_5_4         #Loop back
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
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_4_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v8, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v16, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v24, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v8, v8, t1    
    vslidedown.vx v16, v16, t1
    vslidedown.vx v24, v24, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v9, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v17, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v25, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v9, v9, t1    
    vslidedown.vx v17, v17, t1
    vslidedown.vx v25, v25, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v10, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v18, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v26, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v10, v10, t1    
    vslidedown.vx v18, v18, t1
    vslidedown.vx v26, v26, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v11, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v19, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v27, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v11, v11, t1    
    vslidedown.vx v19, v19, t1
    vslidedown.vx v27, v27, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_4        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_5:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v4, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v12, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v20, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v28, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v4, v4, t1    #Slide down next elements
    vslidedown.vx v12, v12, t1    
    vslidedown.vx v20, v20, t1
    vslidedown.vx v28, v28, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_5        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_6:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v5, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v13, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v21, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v29, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v5, v5, t1    #Slide down next elements
    vslidedown.vx v13, v13, t1    
    vslidedown.vx v21, v21, t1
    vslidedown.vx v29, v29, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_6        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_7:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v6, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v14, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v22, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v30, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v6, v6, t1    #Slide down next elements
    vslidedown.vx v14, v14, t1    
    vslidedown.vx v22, v22, t1
    vslidedown.vx v30, v30, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_7        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_4_8:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v7, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v15, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v23, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v31, (M_pack)       #[3][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v7, v7, t1    #Slide down next elements
    vslidedown.vx v15, v15, t1    
    vslidedown.vx v23, v23, t1
    vslidedown.vx v31, v31, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_4_8        #Loop back
    bgtz K, K_loop_3            #loop back if K > 0
    j End
K_loop_3:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               
    vmv.v.i v16, 0              
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v0, (M_addr), t6   #load row 1
    add t2, M_addr, t5          #point row 2
    vlse16.v v8, (t2), t6       #load row 2
    add t2, t2, t5              #point row 3
    vlse16.v v16, (t2), t6      #load row 3
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_3_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v8, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v16, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v8, v8, t1    
    vslidedown.vx v16, v16, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v9, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v17, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v9, v9, t1    
    vslidedown.vx v17, v17, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v10, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v18, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v10, v10, t1    
    vslidedown.vx v18, v18, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v11, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v19, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v11, v11, t1    
    vslidedown.vx v19, v19, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_4        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_5:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v4, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v12, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v20, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v4, v4, t1    #Slide down next elements
    vslidedown.vx v12, v12, t1    
    vslidedown.vx v20, v20, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_5        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_6:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v5, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v13, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v21, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v5, v5, t1    #Slide down next elements
    vslidedown.vx v13, v13, t1    
    vslidedown.vx v21, v21, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_6        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_7:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v6, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v14, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v22, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v6, v6, t1    #Slide down next elements
    vslidedown.vx v14, v14, t1    
    vslidedown.vx v22, v22, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_7        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_3_8:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v7, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v15, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack
    vse16.v v23, (M_pack)       #[2][0-7]
    sh1add M_pack, t1, M_pack  
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v7, v7, t1    #Slide down next elements
    vslidedown.vx v15, v15, t1    
    vslidedown.vx v23, v23, t1
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_3_8        #Loop back
    bgtz K, K_loop_3            #loop back if K > 0
    j End
K_loop_2:
    vsetvli t0, zero, e16, m8
    vmv.v.i v0, 0               # reset
    vmv.v.i v8, 0               
    vmv.v.i v16, 0              
    vmv.v.i v24, 0              
    vsetvli t0, K, e16, m8      #VL = min(K,512)
    vlse16.v v0, (M_addr), t6   #load row 0 first chunk
    add t2, M_addr, t5          #row 1 address
    vlse16.v v8, (t2), t6       #load row 1 first chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_1:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v0, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v8, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v0, v0, t1    #Slide down next elements
    vslidedown.vx v8, v8, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_1        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_2_2:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v1, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v9, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v1, v1, t1    #Slide down next elements
    vslidedown.vx v9, v9, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_2        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_2_3:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v2, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v10, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v2, v2, t1    #Slide down next elements
    vslidedown.vx v10, v10, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_3        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_2_4:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v3, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v11, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v3, v3, t1    #Slide down next elements
    vslidedown.vx v11, v11, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_4        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_2_5:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v4, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v12, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v4, v4, t1    #Slide down next elements
    vslidedown.vx v12, v12, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_5        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_2_6:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v5, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v13, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v5, v5, t1    #Slide down next elements
    vslidedown.vx v13, v13, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_6        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1    
K_loop_2_7:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v6, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v14, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v6, v6, t1    #Slide down next elements
    vslidedown.vx v14, v14, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_7        #Loop back
    beqz K, End                #End if no elements left
    vsetvli t0, K, e16, m1
K_loop_2_8:
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v7, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v15, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v7, v7, t1    #Slide down next elements
    vslidedown.vx v15, v15, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_8        #Loop back
    beqz K, End                #End if no elements left
    #SECOND CHUNK
    vsetvli t0, K, e16, m8      #VL = min(K,256), avoid reading out of bounds
    vlse16.v v16, (M_addr), t6  #load row 0 second chunk
    add t2, M_addr, t5          #row 1 address
    vlse16.v v24, (t2), t6      #load row 1 second chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_9:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v16, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v24, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v16, v16, t1    #Slide down next elements
    vslidedown.vx v24, v24, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_9       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_10:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v17, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v25, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v17, v17, t1    #Slide down next elements
    vslidedown.vx v25, v25, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_10       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_11:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v18, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v26, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v18, v18, t1    
    vslidedown.vx v26, v26, t1    #Slide down next elements
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_11       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_12:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v19, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v27, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v19, v19, t1    
    vslidedown.vx v27, v27, t1    #Slide down next elements
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_12       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_13:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v20, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v28, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v20, v20, t1    
    vslidedown.vx v28, v28, t1    #Slide down next elements
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_13       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_14:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v21, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v29, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v21, v21, t1    
    vslidedown.vx v29, v29, t1    #Slide down next elements
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_14       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_15:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v22, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v30, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v22, v22, t1    
    vslidedown.vx v30, v30, t1    #Slide down next elements
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_15       #Loop back
    beqz K, End                 #End if no elements left
    vsetvli t0, K, e16, m1     #VL = min(t0,64), max elements in vector
K_loop_2_16:    
    vsetvli t1, K, e16, mf8    #VL = min(t0,8)    
    vse16.v v23, (M_pack)        #[1][0-7]
    sh1add M_pack, t1, M_pack   #Advance pointer stored-elements bytes
    vse16.v v31, (M_pack)        #[0][0-7]
    sh1add M_pack, t1, M_pack   
    vsetvli t2, K, e16, m1     #Use m1 to slide
    vslidedown.vx v23, v23, t1    #Slide down next elements
    vslidedown.vx v31, v31, t1    
    sub t0, t0, t1              #Subtract processed elements from loop total
    sub K, K, t1
    bnez t0, K_loop_2_16       #Loop back
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
    sh1add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    beqz K, End
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v8, (M_addr), t6   #load next row chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v8, (M_pack)        #[0][256-511]
    sh1add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    beqz K, End
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v16, (M_addr), t6  #load next row chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v16, (M_pack)       #[0][512-767]
    sh1add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    beqz K, End
    vsetvli t0, K, e16, m8      #VL = min(K,256)
    vlse16.v v24, (M_addr), t6  #load next row chunk
    mul t1, t0, t6
    add M_addr, M_addr, t1
    vse16.v v24, (M_pack)       #[0][768-1024]
    sh1add M_pack, t0, M_pack   # advance M_pack address based on saved elements
    sub K, K, t0                #K counter -= VL
    bgtz K, K_loop_1            #loop back if K > 0
End:
    ret
