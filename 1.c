#include <pthread.h> //Библа для потоков
#include <stdio.h> //Вводы выводы
#include <unistd.h> //sleep()

void *any_func(void *args) //Функция потока из мануала
{
	int i;
	for(i = 0; i < 10; i ++) //Выводим 10 раз строку
	{
		printf("Child Thread. Iteration: %d\n", i + 1);

		sleep(2); //Спим 2 секунды
	}

	return NULL;
}

int main(void)
{
	int i, result;
	pthread_t thread;

	result = pthread_create(&thread, NULL, &any_func, NULL); //Первый NULL значит что мы создали поток с атрибутами по-умолчанию.
	if (result != 0) //Если создать поток не получилось.
	{
		fprintf(stderr, "Error\n");
		return 1;
	}

	for (i = 0; i < 10; i ++) //Выводим 10 раз строку
	{
		printf("Main Thread. Iteration: %d\n", i + 1);

		sleep(2); //Спим 2 секунды
	}

	sleep(3);
}
