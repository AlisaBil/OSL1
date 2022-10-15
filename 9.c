#include <unistd.h>
#include <stdio.h>
#include <sys/utsname.h>

int gethostname(char *name, size_t namelen);
long gethostid(void);
int uname(struct utsname *name);

int main()
{
    struct utsname computer;
    struct utsname *ptr = &computer;
    char name[10];

    uname(ptr);
    gethostname(name, 10);
    printf("id = %d - name = %s\nrelease = %s\nversion = %s\nmachine = %s", gethostid(), name, computer.release, computer.version, computer.machine);

    return 0;
}