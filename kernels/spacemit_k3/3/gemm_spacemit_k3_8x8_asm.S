	.text
	.balign 4
	.global gemm_spacemit_k3_8x8_asm
# RV64IDV system

# Function Signature:
#void gemm_spacemit_k3_8x8_asm(dim_t m, dim_t n, dim_t k, const _Float16* A, const _Float16* B, float* C, int rs_c, int cs_c, float alpha, float beta);
# c += a * b (alpha=1, no transpose)

#define M a0
#define N a1
#define K a2
#define A_addr a3 
#define B_addr a4 
#define C_addr a5
#define C_rs a6
#define C_cs a7
#define alpha fa0
#define beta fa1


gemm_spacemit_k3_8x8_asm:
    vsetvli t0, zero, e32, m2
    vmv.v.i v30, 0                       # reset accumulator
    li t2, 8                             # vfwmadot can compute up to 8 elements per row/col
    blt K, t2, K_tail                    # handle tail if less than 8 elements per row/col remaining
K_loop:                            
    vsetvli t0, zero, e16, m8            # reset all registers to zero
    vmv.v.i v0, 0                        #0-7                   
    vmv.v.i v8, 0                        #8-15  
    vmv.v.i v16, 0                       #16-23
    vsetvli t0, zero, e16, m2            # 
    vmv.v.i v24, 0                       #24-25 
    vmv.v.i v26, 0                       #26-27 
    vmv.v.i v28, 0                       #28-29 
####VMADOT BLOCK 1
    slli t0, M, 3                        # M * 8 elems from A
    vsetvli t0, t0, e16, m1              
    vle16.v v29, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                        # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v28, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr            # move B pointer
    vfwmadot v30, v29, v28               # vmadot
    vsetvli t0, zero, e32, m2,           # use 32 bit elements
    sub K, K, t2                         # K -= 8
    blt K, t2, K_tail                    # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 2
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v27, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                        # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v26, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr               # move B pointer
    vfwmadot v30, v27, v26                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 3
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v25, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v24, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr               # move B pointer
    vfwmadot v30, v25, v24                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 4
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v23, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v22, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr               # move B pointer
    vfwmadot v30, v23, v22                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 5
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v21, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v20, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr               # move B pointer
    vfwmadot v30, v21, v20                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 6
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v19, (A_addr)                 # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v18, (B_addr)                 # load source 2 fron B 
    sh1add B_addr, t0, B_addr               # move B pointer
    vfwmadot v30, v19, v18                   # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 7
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v17, (A_addr)                 # load source 1 from A
    sh1add A_addr, t0, A_addr            # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v16, (B_addr)                 # load source 2 fron B 
    sh1add B_addr, t0, B_addr               # move B pointer
    vfwmadot v30, v17, v16                   # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 8
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v15, (A_addr)               # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v14, (B_addr)               # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v15, v14              # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 9
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v13, (A_addr)               # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v12, (B_addr)               # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v13, v12              # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 10
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1  
                 
    vle16.v v11, (A_addr)               # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v10, (B_addr)               # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v11, v10              # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 11
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v9, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v8, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v9, v8                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 12
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v7, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v6, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v7, v6                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 13
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v5, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v4, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v5, v4                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
####VMADOT BLOCK 14
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v3, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v2, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v3, v2                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining    
####VMADOT BLOCK 15
    slli t0, M, 3                       # M * 8 elems from A
    vsetvli t0, t0, e16, m1               
    vle16.v v1, (A_addr)                # load source 1 from A
    sh1add A_addr, t0, A_addr           # move A pointer
    slli t0, N, 3                       # N * 8 elems from B
    vsetvli t0, t0, e16, m1
    vle16.v v0, (B_addr)                # load source 2 fron B 
    sh1add B_addr, t0, B_addr           # move B pointer
    vfwmadot v30, v1, v0                # vmadot
    vsetvli t0, zero, e32, m2,          # use 32 bit elements
    sub K, K, t2                        # K -= 8
    blt K, t2, K_tail                   # handle tail if less than 8 elements per row/col remaining
###K loop end
    j K_loop                            # re run loop if more than 8 elements left
###Handle K smaller than 8
K_tail:
    beqz K, Store                        # K == 0 ? Nothing left to compute  
    vsetvli t0, zero, e16, m1,           #reset registers that are going to be used 
    vmv.v.i v0, 0                        #mask
    vmv.v.i v1, 0                        #iota
    vmv.v.i v2, 0                        #vmadot source 1
    vmv.v.i v3, 0                        #vmadot source 2
    vmv.v.i v4, 0                        #vmadot result
    vmv.v.i v5, 0                        #vmadot result

    vid.v v1                             #load vector indices 
    vand.vi v1, v1, 7                    #modulo 8 each element, only keep the last 3 bits
    vmsltu.vx v0, v1, K                  #mask true if element index lower than remaining elements
    viota.m v1, v0                       #masked iota, vector will contain indices of wanted elements from vmadot source operand
####A remainder load
    mul t0, K, M                         # K elements * A remaining rows
    vsetvli t0, t0, e16, m1,              
    vle16.v v4, (A_addr)                 # load source1 into vmadot result 1 temporarily
####B remainder load 
    mul t0, K, N                         # K elements * B remaining columns
    vsetvli t0, t0, e16, m1,              
    vle16.v v5, (B_addr)                 # load source2 into vmadot result 2 temporarily
####Sparse A/B vmadot
    vsetvli t0, zero, e16, m1,             
    vrgather.vv v2, v4, v1, v0.t         #masked gather onto a zeroed array, result will contain active source elements separated by zeroes 
    vrgather.vv v3, v5, v1, v0.t         #same for source 2
    vfwmadot v30, v2, v3                 # vmadot
    vsetvli t0, zero, e32, m2,         
Store:
####Store accumulated result
    vsetvli t2, zero, e32, m2,           # zero out v22-29, will be used to load C values
    vmv.v.i v22, 0                       # row 7-8 
    vmv.v.i v24, 0                       # row 5-6
    vmv.v.i v26, 0                       # row 3-4
    vmv.v.i v28, 0                       # row 1-2
    vsetvli t0, N, e32, m1,              # t0 has the # of elements of the row to store
    slli t2, C_cs, 2                     # Row stride in bytes
### Store C[0][0-N]
    vlse32.v v29, (C_addr), t2           # load previous content of C first row
    vfmul.vf v30, v30, alpha             # AB * alpha, applies to the whole vector
    vfmacc.vf v30, beta, v29             # C = beta * previous C
    vsse32.v v30, (C_addr), t2           # store elements of first row
    li t1, 1                             # processed row counter
    beq M, t1, End                       # M == 1? done
### Store C[1][0-N]
    addi t1, t1, 1                       # row count ++
    sh2add C_addr, C_rs, C_addr          # next row  = C start address + (row stride << 2)
    vslidedown.vi v30, v30, 8            # slide second row to front
    vlse32.v v28, (C_addr), t2           # load previous content of C second row
    vfmacc.vf v30, beta, v28             # C = beta * previous C
    vsse32.v v30, (C_addr), t2           # store elements of second row
    beq M, t1, End                       # M == 2? done
### Store C[2][0-N]
    addi t1, t1, 1                       # row count ++
    sh2add C_addr, C_rs, C_addr          # next row  = C start address + (row stride << 2)
    vslidedown.vi v30, v30, 16           # slide third row to front
    vlse32.v v27, (C_addr), t2           # load previous content of C third row
    vfmacc.vf v30, beta, v27             # C = beta * previous C
    vsse32.v v30, (C_addr), t2           # store elements of third row
    beq M, t1, End                       # M == 3? done
### Store C[3][0-N]
    addi t1, t1, 1                       # row count ++
    sh2add C_addr, C_rs, C_addr          # next row  = C start address + (row stride << 2)
    vslidedown.vi v30, v30, 24           # slide fourth row to front
    vlse32.v v26, (C_addr), t2           # load previous content of C fourth row
    vfmacc.vf v30, beta, v26             # C = beta * previous C
    vsse32.v v30, (C_addr), t2           # store elements of fourth row
    beq M, t1, End                       # M == 4? done
### Store C[4][0-N]
    addi t1, t1, 1                       # row count ++
    sh2add C_addr, C_rs, C_addr          # next row  = previous row + (row stride << 2)
    vlse32.v v25, (C_addr), t2           # load previous content of C fifth row
    vfmul.vf v31, v31, alpha             # AB * alpha, applies to the whole vector
    vfmacc.vf v31, beta, v25             # C = beta * previous C
    vsse32.v v31, (C_addr), t2           # store elements of fifth row
    beq M, t1, End                       # M == 5? done
### Store C[5][0-N]
    addi t1, t1, 1                       # row count++
    sh2add C_addr, C_rs, C_addr          # next row  = previous row + (row stride << 2)
    vslidedown.vi v31, v31, 8            # slide sixth to front
    vlse32.v v24, (C_addr), t2           # load previous content of C sixth row
    vfmacc.vf v31, beta, v24             # C = beta * previous C
    vsse32.v v31, (C_addr), t2           # store elements of sixth row
    beq M, t1, End                       # M == 6? done
### Store C[6][0-N]
    addi t1, t1, 1                       # row count++
    sh2add C_addr, C_rs, C_addr          # next row  = previous row + (row stride << 2)
    vslidedown.vi v31, v31, 16           # slide seventh to front
    vlse32.v v23, (C_addr), t2           # load previous content of C seventh row
    vfmacc.vf v31, beta, v23             # C = beta * previous C
    vsse32.v v31, (C_addr), t2           # store elements of seventh row
    beq M, t1, End                       # M == 6? done
### Store C[7][0-N]
    sh2add C_addr, C_rs, C_addr          # next row  = previous row + (row stride << 2)
    vslidedown.vi v31, v31, 24           # slide eighth to front
    vlse32.v v22, (C_addr), t2           # load previous content of C eighth row
    vfmacc.vf v31, beta, v22             # C = beta * previous C
    vsse32.v v31, (C_addr), t2           # store elements of eighth row
###End of store
End:
    ret