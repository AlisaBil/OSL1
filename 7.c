#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int clearenv(void);
extern char **environ;

int main(int argc, char **argv)
{
    const struct option long_opt[] = {
        {"help", 0, 0, 'h'},
        {"name", 1, 0, 'n'},
        {NULL,0,NULL,0}
    };

    int opt;
    char *name;

    while ((opt = getopt_long(argc, argv, "n:h", long_opt, NULL)) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("Please enter name of environment variable\nExample: ./5.out --n test");
            return 0;
        case 'n':
            name = optarg;
            break;
        case '?':
            fprintf(stderr, "%s\n", "Unknown option");
            return 0;
        default:
            return 0;
        }
    }

    if (name == NULL)
    {
        clearenv();
    }
    else
    {
        unsetenv(name);
    }

    printf("Your environment: %s", environ);

    return 0;
}