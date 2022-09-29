#include <stdio.h>
#include <math.h>
#include <malloc.h>

struct point
{
    int mass;
    int pos;
};

int main()
{
    int i, n, j;
    struct point points[100];

    printf("Enter number of points: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int mass, pos;

        printf("\nMass of %d point: ", i + 1);
        scanf("%d", &mass);
        printf("Pos of %d point: ", i + 1);
        scanf("%d", &pos);

        points[i].mass = mass;
        points[i].pos = pos;
    }

    int safeSize = n - 1;
    int pos;
    struct point point;
    for (i = 0; i < safeSize; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            int closestPos = 100000;

            if (closestPos > points[j].pos)
            {
                closestPos = points[j].pos;
                pos = j;
            }
        }

        point = points[pos];
        points[0].mass += point.mass;

        for (j = pos; j < n - 1; j++)
        {
            points[j] = points[j + 1];
        }

        n--;
    }

    printf("\nMass of big point: %d", points[0].mass);
}