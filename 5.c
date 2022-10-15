#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

char *getenv(const char *name);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Please enter name of environment variable\nExample: ./5.out -n test");
        return 0;
    }

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
            printf("Please enter name of environment variable\nExample: ./5.out -n test");
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

    printf("Your variable: %s", getenv(name));

    return 0;
}