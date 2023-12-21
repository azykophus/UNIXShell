#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char *argv[]){
    if (argc==1){
        char dirName[16];
        int ret = 0;

        printf("Enter directory name: ");
        scanf("%s", dirName);

        ret = mkdir(dirName, 0755);

        if (ret == 0)
            printf("Directory created successfully\n");
        else
            printf("Unable to create directory %s\n", dirName);   
    }
    else if (argc==3){
        char dirName[16];
        int ret = 0;

        printf("Enter directory name: ");
        scanf("%s", dirName);

        ret = mkdir(dirName, 0755);

        if (ret == 0)
            printf("Directory created successfully\n");
        else
            printf("Unable to create directory %s\n", dirName);   
    }

    return 0;
}