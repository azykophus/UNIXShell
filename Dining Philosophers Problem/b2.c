#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *check_error_sem(int *i1, int *i2)
{
    if (i1)
    {
        if (i2 == 0)
        {
            printf("error in sem_init()");
        }
        else if (i2 == 1)
        {
            printf("error in sem_wait()");
        }
        else if (i2 == 2)
        {
            printf("error in sem_post()");
        }
        else
        {
            printf("error!");
        }
        exit(1);
    }
    return NULL;
}

#define NUM_PHILOSOPHERS 5
#define NUM_FORKS 5
#define NUM_BOWLS 2

pthread_mutex_t forks[NUM_FORKS];
pthread_mutex_t bowls[NUM_BOWLS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *startthinking(void *id)
{
    int *philosopher_id = (int *)id;

    {
        printf("Philosopher %d is thinking\n", *philosopher_id);

        if (*philosopher_id % 2 == 1)
        {

            pthread_mutex_lock(&forks[*philosopher_id]);

            printf("Philosopher %d picks first fork\n", *philosopher_id);

            pthread_mutex_lock(&forks[(*philosopher_id + 1) % NUM_PHILOSOPHERS]);

            printf("Philosopher %d picks second fork\n", *philosopher_id);
        }
        else
        {

            pthread_mutex_lock(&forks[(*philosopher_id + 1) % NUM_PHILOSOPHERS]);

            printf("Philosopher %d pciks first fork\n", *philosopher_id);
            pthread_mutex_lock(&forks[*philosopher_id]);

            printf("Philosopher %d picks second fork\n", *philosopher_id);
        }

        pthread_mutex_lock(&bowls[*philosopher_id % NUM_BOWLS]);

        printf("Philosopher %d gets bowl\n", *philosopher_id);
        printf("Philosopher %d is eating\n", *philosopher_id);
        sleep(2);

        pthread_mutex_unlock(&bowls[*philosopher_id % NUM_BOWLS]);

        printf("Philosopher %d drops bowl\n", *philosopher_id);

        pthread_mutex_unlock(&forks[*philosopher_id]);

        printf("Philosopher %d drops fork 1\n", *philosopher_id);
        pthread_mutex_unlock(&forks[(*philosopher_id + 1) % NUM_PHILOSOPHERS]);

        printf("Philosopher %d drops fork 2\n", *philosopher_id);
    }
}

int main()
{

    int args[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_init(&bowls[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        args[i] = i;
        pthread_create(&philosophers[i], NULL, startthinking, &args[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(philosophers[i], NULL);
    }
    return 0;
}