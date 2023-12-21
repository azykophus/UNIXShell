#define _GNU_SOURCE

#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>


#define SYS_kernel_2d_memcpy 449

int main(int argc, char** argv){
    float arra[5][4] = {
        {4.030, 6.300, 3.100, 2.300},
        {4.050, 6.303, 3.200, 2.320},
        {4.070, 6.310, 3.300, 2.340},
        {4.090, 6.320, 3.400, 2.467},
        {4.100, 6.350, 3.123, 2.908},
    };

    float arr_copy[5][4];
    

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", arra[i][j]);
        }
        printf("\n");
    }

    int ret_val = syscall(SYS_kernel_2d_memcpy, arra, arr_copy, 80);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", arr_copy[i][j]);
        }
        printf("\n");
    }
    
    printf("\n%d\n", ret_val); 

    return 0;
}