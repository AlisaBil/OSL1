#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> //atoi(), rand()

void * print_msg(void * arg) //Функция для потока (вывод сообщения)
{
	int i, n = *(int*) arg;
	for (i = 0; i < n; i++)
	{
		printf("Print_msg Tread. Iteration: %d\n", i);

		sleep(2);
	}

	pthread_exit(NULL);
}

void * any_func(void * arg) //Функция для потока (рандомное число)
{
	int i, x, n = *(int*) arg;
	for (i = 0; i < n; i++) 
	{ 
		x = rand() % (n + 1); //Рандомное целое число от 0 до n

		if (x == n) //Если рандомное число совпадает с заданным то закончить поток преждевременно
		{
			printf("Any_func Thread. Random number is equal to entered number! (%d)\n", n);
			pthread_exit(NULL);
		}
		else 
		{
			printf("Any_func Thread. Random: %d\n", x);	
		}
	}

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	srand(time(NULL)); //Для того чтобы рандом был разным

	if(argc < 2) //Если мало аргументов в командной строке после запуска программы
	{
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}

	int number = atoi(argv[1]); //Первый аргумент командной строки
	pthread_t thread1, thread2;
	
	//Создаем потоки
	if(pthread_create(&thread1, NULL, &print_msg, &number) != 0)
	{
		fprintf(stderr, "Error on 1\n");
		return 1;
	}

	if(pthread_create(&thread2, NULL, &any_func, &number) != 0)
	{
		fprintf(stderr, "Error on 2\n");
		return 1;
	}
	
	//Ждём их завершения
	if(pthread_join(thread1, NULL) != 0)
	{
		fprintf(stderr, "Join error on 1\n");
		return 1;
	}

	if(pthread_join(thread2, NULL) != 0)
	{
		fprintf(stderr, "Join error on 2\n");
		return 1;
	}

	//Пишем что все наконец-то закончилось (выводим свое сообщение)
	fprintf(stderr, "The End!\n");
}
