#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *consumer_thread(void *arg);
void *conductor_thread(void *arg);

sem_t conductor_sem;
sem_t consumer_sem;
sem_t complite_sem;

int *arr, currentN = 0, n, min, max;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc < 5) //Если аргументов в командной строке мало то ошибка
	{
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}
    int seconds = atoi(argv[1]);
    n = atoi(argv[2]); min = atoi(argv[3]); max = atoi(argv[4]);
    arr = malloc(sizeof(int) * n);

    pthread_t conductor, consumer;
    void *thread_result;

    sem_init(&conductor_sem, 1, 0);
    sem_init(&consumer_sem, 1, n);
    sem_init(&complite_sem, 1, 1);

    pthread_create(&consumer, NULL, consumer_thread, NULL);
    pthread_create(&conductor, NULL, conductor_thread, NULL);

    sleep(seconds);

    pthread_cancel(conductor);
    pthread_cancel(consumer);

    exit(EXIT_SUCCESS);
}

void *consumer_thread(void *arg) {
    while (1) {
        sleep(2);
        sem_wait(&conductor_sem);
        sem_wait(&complite_sem);

        arr[currentN] = 0;
        currentN--;

        sem_post(&complite_sem);
        sem_post(&consumer_sem);
        
        int i;
        for (i = 0; i < currentN; i++) {
            fprintf(stderr, "%d ", arr[i]);
        }

        fprintf(stderr, " - Consume\n");
    }

    pthread_exit(NULL);
}

void *conductor_thread(void *arg) {
    while (1) {
        sleep(1);
        int numb = rand() % (max + min) - min; 

        sem_wait(&consumer_sem);
        sem_wait(&complite_sem);

        arr[currentN] = numb;
        currentN++;

        sem_post(&conductor_sem);
        sem_post(&complite_sem);

        int i;
        for (i = 0; i < currentN; i++) {
            fprintf(stderr, "%d ", arr[i]);
        }

        fprintf(stderr, " - Conduct\n");
    }

    pthread_exit(NULL);
}