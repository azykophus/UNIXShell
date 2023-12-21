#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>

#define MAX 100
double all[MAX];
int t = 0;

void CountA()
{
    clock_t start, end;
    double execution_time;
    start = clock();

    for (long long i = 0; i < pow(2, 32); i++)
    {
        ;
    }
    end = clock();
    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    end = clock();
    FILE *file = fopen("output.txt", "a+");

    fprintf(file, "%f ", (double)execution_time);
}

void CountB()
{
    clock_t start, end;
    double execution_time;
    start = clock();

    for (long long i = 0; i < pow(2,32); i++)
    {
        ;
    }

    end = clock();
    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    end = clock();

    FILE *file = fopen("output.txt", "a+");

    fprintf(file, "%f ", (double)execution_time);
}

void CountC()
{
    clock_t start, end;
    double execution_time;
    start = clock();

    for (long long i = 0; i < pow(2, 32); i++)
    {
        ;
    }

    end = clock();
    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    end = clock();

    FILE *file = fopen("output.txt", "a+");

    fprintf(file, "%f ", (double)execution_time);
}
int main()
{
    FILE *file = fopen("output.txt", "w");
    fclose(file);
    int x = 0;
    while (x < 105)
    {
        pthread_t CountA_thread=NULL;
        pthread_t CountB_thread=NULL;
        pthread_t CountC_thread=NULL;

        pthread_create(&CountA_thread, NULL, &CountA, NULL);
        pthread_create(&CountB_thread, NULL, &CountB, NULL);
        pthread_create(&CountC_thread, NULL, &CountC, NULL);

        struct sched_param CountA_param;
        pthread_setschedparam(CountA_thread, SCHED_OTHER, &CountA_param);
        CountA_param.sched_priority = x;
        

        struct sched_param CountB_param;
        CountB_param.sched_priority = x;
        pthread_setschedparam(CountB_thread, SCHED_RR, &CountB_param);
        

        struct sched_param CountC_param;
        CountC_param.sched_priority = x;
        pthread_setschedparam(CountC_thread, SCHED_FIFO, &CountC_param);


        pthread_join(CountA_thread, NULL);
        pthread_join(CountB_thread, NULL);
        pthread_join(CountC_thread, NULL);
        x = x + 20;
        FILE *file = fopen("output.txt", "a+");

        fprintf(file, "\n");
    }
}