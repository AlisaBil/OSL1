#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h> //Для динамического выделения памяти

int factorial(int n) //Считаем факториал классическим методом (прямым), так как в жизни бы считала
{
	int i, result = 1;

	if (n == 0) //Если 0 то вернуть 1 (0! = 1)
	{
		return 1;
	}

	for (i = 1; i <= n; i++)
	{
		result *= i; // result = 1 * 2 * 3 * ... * n
	}

	return result;
}

void * catalan(void * arg) //Считаем числа каталана по формуле из мануала
{
	int i, n = *(int*) arg; //Принимаем целочисленное значение из аргумента

	int *arr = malloc(sizeof(int) * n); //Задаем динамический массив целых чисел на n элементов
	for( i = 0; i < n; i ++)
	{
		arr[i] = factorial(2 * i) / (factorial(i + 1) * factorial(i)); //Считаем числа Каталана
	}

	return (void *) arr; //Возвращаем массив
}

void * simple(void * arg) //Считаем простые числа
{
	int i = 2, n = *(int*) arg;

	int curSimpleNumbers = 0;
	int *arr = malloc(sizeof(int) * n);

	while (curSimpleNumbers != n) //Пока не найдено столько сколько хотим повторяем
	{
		int j, flag = 0;

		for (j = 2; j < i; j++) //Проверяем составное ли число поиском делителей отличных от единички и самого числа
		{
			if (i % j == 0)
			{
				//Если нашли сразу нет смысла дальше идти по циклу значит чисто уже и так составное
				flag = 1;
				break;
			}
		}

		if (flag == 0) //Если число простое то добавляем его в наш массив
		{
			arr[curSimpleNumbers] = i;

			curSimpleNumbers++;
		}

		i++;
	}

	return (void *) arr;
}

int main(int argc, char *argv[])
{
	if (argc < 2) //Если аргументов в командной строке мало то ошибка
	{
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}
	int n = atoi(argv[1]); //Считываем то что написали в консольке

	//Задаем потоки и массивы которые прочитают то что потоки возвращают
	pthread_t thread1, thread2;
	int *arr1, *arr2;
	
	//Создаем поток
	if (pthread_create(&thread1, NULL, &catalan, &n) != 0)
	{
		fprintf(stderr, "Error (thread1)\n");
		return 1;
	}
	pthread_join(thread1, (void *) &arr1); //Читаем его возврат в arr1

	//Создаем поток
	if (pthread_create(&thread2, NULL, &simple, &n) != 0)
	{
		fprintf(stderr, "Error (thread2)\n");
		return 1;
	}
	pthread_join(thread2, (void *) &arr2); //Читаем его возврат в arr2
	 
	int i;

	fprintf(stderr, "Catalan: ");
	for (i = 0; i < n; i++) //Выводим числа Каталана
	{
		fprintf(stderr, "%d ", arr1[i]);
	}

	fprintf(stderr, "\n\nPrime Numbers: ");
	for (i = 0; i < n; i++) //Выводим простые числа
	{
		fprintf(stderr, "%d ", arr2[i]);
	}
}
