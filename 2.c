#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

double b = 2.0, a = 0.0;

pthread_mutex_t key;
double res = 0, h;

double f(double x) {
	return 4 - pow(x, 2);
}

void *count_integral_elem(void * arg) {
	int i = *(int*) arg;	
	pthread_mutex_lock(&key);
	res += f(a + h*(i + 0.5));
	pthread_mutex_unlock(&key);
}

int main(int argc, char **argv) {
    if (argc < 2) //Если аргументов в командной строке мало то ошибка
	{
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}
	int p = atoi(argv[1]); h = (b - a) / p;
	pthread_t *p_thread = malloc(sizeof(pthread_t) * p);
	
    pthread_mutex_init(&key, NULL);

	int i;
	for (i = 0; i < p; i++) 
		pthread_create(&p_thread[i], NULL, &count_integral_elem, &i);		

	for (i = 0; i < p; i++) 
		pthread_join(p_thread[i], NULL);

	printf("Значение интеграла: %f\n", res * h);

	pthread_mutex_destroy(&key);
	free(p_thread);
}
