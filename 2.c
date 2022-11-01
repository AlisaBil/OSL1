#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(void) 
{
    time_t start;
    time_t finish;
    pid_t pid; /* идентификатор процесса */
    printf("Пока всего один процесс\n");

    printf("Вызов функции fork...\n");
    pid = fork(); /* Создание нового процесса */

    if (pid == 0) 
    {
        printf("Процесс - потомок\n");
    } 
    else if (pid > 0) 
    {
        printf("Родительский процесс, pid потомка %d\n", pid);
    } 
    else 
    {
        printf("Ошибка вызова fork, потомок не создан\n"); 
    }

    int sub = 0;

    time(&start);
    while((difftime(finish, start)) < 5/*пока не прошло 5 секунд нужно выполнять вот это...*/)
    {
        time(&finish);
        sub++;
    }

    printf("Провека на процес, переменная sub: %d\n", sub);
}