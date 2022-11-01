#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t getpgrp(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);

int main()
{
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d", getpid(), getppid(), getpgrp(), getuid(), geteuid(), getegid());
}