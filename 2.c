#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *consumer_thread(void *arg);
void *conductor_thread(void *arg);
void set_thread_flag (int flag_value);
void initialize_flag();

int *arr, currentN = 0, n, min, max, thread_flag;

pthread_mutex_t thread_flag_mutex;

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

    initialize_flag();

    pthread_create(&consumer, NULL, consumer_thread, NULL);
    pthread_create(&conductor, NULL, conductor_thread, NULL);

    sleep(seconds);

    pthread_cancel(conductor);
    pthread_cancel(consumer);

    exit(EXIT_SUCCESS);
}

void *consumer_thread(void *arg) {
    while (1) {
        int flag_is_set;

        pthread_mutex_lock(&thread_flag_mutex);
        flag_is_set = thread_flag;
        pthread_mutex_unlock(&thread_flag_mutex);

        if (flag_is_set) {
            arr[currentN] = 0;
            currentN--;

            int i;
            for (i = 0; i < currentN; i++) {
                fprintf(stderr, "%d ", arr[i]);
            }

            fprintf(stderr, " - Consume\n");

            set_thread_flag(0);
        }
    }

    pthread_exit(NULL);
}

void *conductor_thread(void *arg) {
    while (1) {
        sleep(2);
        int numb = rand() % (max + min) - min; 

        arr[currentN] = numb;
        currentN++;

        int i;
        for (i = 0; i < currentN; i++) {
            fprintf(stderr, "%d ", arr[i]);
        }

        fprintf(stderr, " - Conduct\n");

        set_thread_flag(1);
    }

    pthread_exit(NULL);
}

void set_thread_flag (int flag_value) {
    pthread_mutex_lock (&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_mutex_unlock (&thread_flag_mutex);
}

void initialize_flag () {
    pthread_mutex_init (&thread_flag_mutex, NULL);
    thread_flag = 0;
}