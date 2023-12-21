#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include<stdio.h>
#include<time.h>

#define NUM_PHILOSOPHERS 5
#define NUM_FORKS 5
#define TIME 2
sem_t forks[NUM_FORKS];

sem_t *philosopher(void *num)
{
    int philosopher_num = (int)num;
    int left_fork = philosopher_num;
    int rf = (philosopher_num + 1) % NUM_FORKS;


    {
        printf("Philosopher %ld is thinking\n", philosopher_num);
        sem_wait(&forks[left_fork]);
        sem_wait(&forks[rf]);
        printf("Philosopher %ld is eating\n", philosopher_num);
        sleep(TIME);
        sem_post(&forks[left_fork]);
        sem_post(&forks[rf]);
    }

    return NULL;
}

void main()
{
    pthread_t philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_FORKS; i++)
    {
        sem_init(&forks[i], 0, 1);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

}