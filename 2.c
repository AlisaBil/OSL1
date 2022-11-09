#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//Структура которую читают наши потоки
struct thread_arg
{
	char *name; 
	char *str;
	int num;
};

void *any_func(void *arg) //Функция одинаковая для всех потоков
{
	struct thread_arg *targ = (struct thread_arg*) arg;

	int i;
	for(i = 0; i < targ->num; i++)
	{
		printf("Thread %s.\t %s\t %d\n", targ->name, targ->str, i+1);	
	} 

	printf("\n\n");

	return NULL;
}

int main(void)
{
	pthread_t thread1, thread2, thread3, thread4; //Инициализация потоков
	
	//Каждый поток должен иметь свой набор параметров
	struct thread_arg targ1 = { "Thread1", "This is first thread", 1};
	struct thread_arg targ2 = { "Thread2", "This is second thread", 2};
	struct thread_arg targ3 = { "Thread3", "This is third thread", 3};
	struct thread_arg targ4 = { "Thread4", "This is fourth thread", 4};
	
	//Создание потоков
	if(pthread_create(&thread1, NULL, &any_func, &targ1) != 0)
	{
		fprintf(stderr, "Error on 1\n");
		return 1;
	}

	if(pthread_create(&thread2, NULL, &any_func, &targ2) != 0)
	{
		fprintf(stderr, "Error on 2\n");
		return 1;
	}

	if(pthread_create(&thread3, NULL, &any_func, &targ3) != 0)
	{
		fprintf(stderr, "Error on 3\n");
		return 1;
	}

	if(pthread_create(&thread4, NULL, &any_func, &targ4) != 0)
	{
		fprintf(stderr, "Error on 4\n");
		return 1;
	}

	sleep(3);
}
