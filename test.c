#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[3];

void eat(int phil)
{
	printf("Philosopher %d is eating\n",phil); 
}

void * philosopher(void *num)
{
	int phil = *(int *)num;

	sem_wait(&room);
	printf("Philosopher %d has entered room\n", phil);
	sem_wait(&chopstick[phil]); 
    sem_wait(&chopstick[(phil + 1) % 3]);

	eat(phil);
	usleep(1);
	printf("Philosopher %d has finished eating\n", phil);

	sem_post(&chopstick[(phil + 1) % 3]);
	sem_post(&chopstick[phil]);
	sem_post(&room);
    return (NULL);
}

int main()
{
	int i;
    int a[3];
	pthread_t tid[3];

	// sem_init(&room, 0, 4);
	
	// for (i = 0; i < 5; i++)
	// 	sem_init(&chopstick[i], 0, 1);
		
	for (i = 0; i < 3; i++)
    {
		a[i] = i;
		pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]);
	}

	for (i = 0; i < 3; i++)
		pthread_join(tid[i], NULL);
}
