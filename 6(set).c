#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int setenv(const char *name, const char *value, int overwrite);
char *getenv(const char *name);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Please enter name of environment variable\nExample: ./5.out --n test --v test");
        return 0;
    }

    const struct option long_opt[] = {
        {"help", 0, 0, 'h'},
        {"value", 1, 0, 'v'},
        {"name", 1, 0, 'n'},
        {NULL,0,NULL,0}
    };

    int opt;
    char *name;
    char *value;

    while ((opt = getopt_long(argc, argv, "n:h:v", long_opt, NULL)) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("Please enter name of environment variable\nExample: ./5.out --n test --v test");
            return 0;
        case 'n':
            name = optarg;
            break;
        case 'v':
            value = optarg;
            break;
        case '?':
            fprintf(stderr, "%s\n", "Unknown option");
            return 0;
        default:
            return 0;
        }
    }

    if (value == NULL || name == NULL)
    {
        printf("You should write name AND value!");
        return 0;
    }

    setenv(name, value, 0);
    printf("Your variable: %s - %s", name, getenv(name));

    return 0;
}