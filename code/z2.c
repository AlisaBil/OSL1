#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main()
{
    int n;
    printf("Enter your array size: ");
    scanf("%d", &n);

    int i, number = 0, flag = 0;
    float *arr = (float *)malloc(n), sum = 0;

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter your %d element: ", i + 1);
        scanf("%f", &arr[i]);
        sum += arr[i];
    }
    float sr = sum / n;
    printf("\nAverage: %.1f\n", sr);

    sum = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] > sr)
        {
            number += 1;
        }
    }
    printf("Number of values > average: %d\n", number);

    for (i = 0; i < n; i++)
    {
        if (flag == 1)
        {
            sum += fabs(arr[i]);
        }

        if (arr[i] < 0)
        {
            flag = 1;
        }
    }
    printf("Sum of values after first number < 0: %.1f", sum);
}