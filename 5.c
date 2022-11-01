#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

void subsystem()
{
    pid_t child_pid;
    int index;

    printf("Создание процесса...\n");
    child_pid = fork();

    printf("Выполнение запроса...\n");
    char *args[] = {"./for5.out", NULL};
    execv(args[0], args);

    if (child_pid > 0)
    {
        printf("Очистка...\n");
        wait(&index);
    }
}

int main()
{
    subsystem();
}