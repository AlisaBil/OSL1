#include <stdio.h> //Ввод и вывод информации
#include <stdlib.h> //RAND_MAX, EXIT_SUCCESS
#include <time.h> //Задаем рандом
#include <math.h> //Математические выражения
#include <string.h> //Чтение количества точек при запуске программы
#include <unistd.h> //fork()
#include <sys/wait.h> //WNOHAMG 

int main(int argc, char *argv[])
{
    srand(time(NULL));
    float r; //Радиус
    int n = atof(argv[1]); //Количество точек (от 0 до 255 надо)
    int sum = 0; //Количество точек в кругу
    int status; //Полученный статус от потомка

    printf("Введите радиус круга: ");
    scanf("%f", &r);

    if (n == NAN) //Если в начале проги не было задано число то ввести его с клавиатуры
    {
        printf("\nВведите количество итераций: ");
        scanf("%d", &n);
    }

    if (!fork()) //Создаем дочерний процесс
    {
        //Считаем количество точек
        int i, circleSum = 0;
        for (i = 0; i < n; i++)
        {
            float x = (float)rand()/(float)(RAND_MAX) * 2 - 1;
            float y = (float)rand()/(float)(RAND_MAX) * 2 - 1;

            if (pow(x, 2) + pow(y, 2) <= 1.0)
            {
                circleSum++;
            }
        }

        //Возвращаем его в родительский процесс
        exit(circleSum);
    }

    //В родительском процессе ждём выполнение дочернего
    while (1) {
        if (!waitpid(-1, &status, WNOHANG)) 
        {
            fprintf(stderr, "Считаем...");
        }
        else 
        {
            fprintf(stderr, "(exit)\n");
            break;
        }
        sleep(2);
    }

    //Если не было никаких ошибок и вышли из потомка без проблем, то взять переданное значение.
    if (WIFEXITED(status)) {
        sum = WEXITSTATUS(status);
    } 

    //Считаем ПИ и площадь круга.
    float pi = (float)sum / n * 4.0;
    printf("\nПлощадь круга: %2f", pi * pow(r, 2));
    printf("\nЧисло PI: %f", pi);

    return EXIT_SUCCESS;
}