#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int opt, flag = 0;
    char *name = "Default";
    
    if (argc == 1)
    {
        printf("-h Help\n-o out_file_name New File Name\n-c Special Mode");
        return 0;
    }

    while ((opt = getopt(argc, argv, "ho:c")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("-h Help\n-o out_file_name New File Name\n-c Special Mode");
            return 0;
        case 'o':
            name = optarg;
            break;
        case 'c':
            printf("You was entered in special mode!");
            flag = 1;
            break;
        default:
            return 0;
        }
    }

    if (flag == 0)
    {
        printf("You are in normal mode!");
    }

    fopen(name, "r");
}