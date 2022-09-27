#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(0));

    int balance = 5000;
    int bid = 500;
    int choice, i;

    while (1)
    {
        printf("1. Play\n2. Combinations\n3. Quit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while (choice != 3 && balance > 0)
            {
                int game[3];

                printf("\nPLAY MODE!!!\nYOUR BALANCE: %d\nYOUR BID: %d\n\n1. Make a bid\n2. Change bid\n3. Quit mode\n", balance, bid);

                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    double multiplier = 1;
                    balance -= bid;

                    for (i = 0; i < 3; i++)
                    {
                        game[i] = rand() % 8;
                        printf("%d ", game[i]);

                        if (i > 0)
                        {
                            if (game[i] == game[i - 1] && (game[i] == 5 || game[i] == 7))
                            {
                                multiplier *= (2 + game[i]);
                            }

                            if (i > 1)
                            {
                                if (game[i] == game[i - 2] && (game[i] == game[i - 1] || game[i] == 5 || game[i] == 7))
                                {
                                    multiplier *= (2 + game[i]);
                                }
                            }
                        }
                    }
			
		    if (multiplier == 1 && (game[0] == 5 || game[1] == 5 || game[2] == 5 || game[0] == 7 || game[1] == 7 || game[2] == 7))
                    {
                        multiplier = 2;
                    }

                    if (game[0] == 5 && game[1] == 5 && game[2] == 5)
                    {
                        multiplier = 50;
                    }

                    if (game[0] == 6 && game[1] == 6 && game[2] == 6)
                    {
                        multiplier = 0.5;
                    }

                    if (game[0] == 7 && game[1] == 7 && game[2] == 7)
                    {
                        printf("JACKPOT!!! YOU WON!!!\n");
                        exit(1);
                    }

                    if (multiplier == 1)
                        printf("\nTRY AGAIN!!!\n");
                    else if (multiplier == 0.5)
                    {
                        printf("\nYOU LOST HALF OF YOUR POINTS!!!\n");
                        balance *= multiplier;
                    }
                    else
                    {
                        printf("\nYOU WON %lf POINTS!!!\n", bid * multiplier);
                        balance += bid * multiplier;
                    }

                    break;
                case 2:
                    printf("\nEnter your bid: ");
                    scanf("%d", &bid);
                    break;
                case 3:
                    printf("\n");
                    break;
                default:
                    printf("Looks loke you enter wrong command! Try again please!");
                    break;
                }
            }

            if (balance == 0)
            {
                printf("\nYOU LOSE!!!\n");
                exit(-1);
            }
            break;
        case 2:
            printf("\nMULTIPLIER X2*(2+NUMBER): 000 111 222 333 444\nMULTIPLIER X2: 5XX 7XX\nMULTIPLIER X2*(2+NUMBER): 55X 77X\nMULTIPLIER X50: 555\nPENALTY: 666\nJACKPOT: 777\n\n");
            break;
        case 3:
            exit(-1);
        default:
            printf("\nLooks like you enter wrong command! Try again please!\n");
            break;
        }
    }

    return 0;
}
