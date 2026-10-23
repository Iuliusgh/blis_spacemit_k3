BLIS_SPACEMIT_TCM=none BLIS_SPACEMIT_TCM_VERBOSE=1 BLIS_NUM_THREADS=1 taskset -c 8 ./test_gemm_vmadot_speed_blis.x | tee none_1th.csv
BLIS_SPACEMIT_TCM=a BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=1 taskset -c 8 ./test_gemm_vmadot_speed_blis.x | tee a_1th.csv
BLIS_SPACEMIT_TCM=b BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=1 taskset -c 8 ./test_gemm_vmadot_speed_blis.x | tee b_1th.csv
BLIS_SPACEMIT_TCM=ab BLIS_SPACEMIT_TCM_VERBOSE=1   BLIS_NUM_THREADS=1 taskset -c 8 ./test_gemm_vmadot_speed_blis.x | tee ab_1th.csv

BLIS_SPACEMIT_TCM=none BLIS_SPACEMIT_TCM_VERBOSE=1 BLIS_NUM_THREADS=2 taskset -c 8,9 ./test_gemm_vmadot_speed_blis.x | tee none_2th.csv
BLIS_SPACEMIT_TCM=a BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=2 taskset -c 8,9 ./test_gemm_vmadot_speed_blis.x | tee a_2th.csv
BLIS_SPACEMIT_TCM=b BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=2 taskset -c 8,9 ./test_gemm_vmadot_speed_blis.x | tee b_2th.csv
BLIS_SPACEMIT_TCM=ab BLIS_SPACEMIT_TCM_VERBOSE=1   BLIS_NUM_THREADS=2 taskset -c 8,9 ./test_gemm_vmadot_speed_blis.x | tee ab_2th.csv

BLIS_SPACEMIT_TCM=none BLIS_SPACEMIT_TCM_VERBOSE=1 BLIS_NUM_THREADS=4 taskset -c 8,9,10,11 ./test_gemm_vmadot_speed_blis.x | tee none_4th.csv
BLIS_SPACEMIT_TCM=a BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=4 taskset -c 8,9,10,11 ./test_gemm_vmadot_speed_blis.x | tee a_4th.csv
BLIS_SPACEMIT_TCM=b BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=4 taskset -c 8,9,10,11 ./test_gemm_vmadot_speed_blis.x | tee b_4th.csv
BLIS_SPACEMIT_TCM=ab BLIS_SPACEMIT_TCM_VERBOSE=1   BLIS_NUM_THREADS=4 taskset -c 8,9,10,11 ./test_gemm_vmadot_speed_blis.x | tee ab_4th.csv

BLIS_SPACEMIT_TCM=none BLIS_SPACEMIT_TCM_VERBOSE=1 BLIS_NUM_THREADS=8 taskset -c 8,9,10,11,12,13,14,15 ./test_gemm_vmadot_speed_blis.x | tee none_8th.csv
BLIS_SPACEMIT_TCM=a BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=8 taskset -c 8,9,10,11,12,13,14,15 ./test_gemm_vmadot_speed_blis.x | tee a_8th.csv
BLIS_SPACEMIT_TCM=b BLIS_SPACEMIT_TCM_VERBOSE=1    BLIS_NUM_THREADS=8 taskset -c 8,9,10,11,12,13,14,15 ./test_gemm_vmadot_speed_blis.x | tee b_8th.csv
BLIS_SPACEMIT_TCM=ab BLIS_SPACEMIT_TCM_VERBOSE=1   BLIS_NUM_THREADS=8 taskset -c 8,9,10,11,12,13,14,15 ./test_gemm_vmadot_speed_blis.x | tee ab_8th.csv
