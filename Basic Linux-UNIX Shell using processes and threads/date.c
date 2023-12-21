#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[]){
    if (argc==1){
        time_t T = time(NULL);
        struct tm tm = *localtime(&T);
        printf("System Date is: %02d/%02d/%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
    else if (argc==2){
        
    }
    return 0;
}