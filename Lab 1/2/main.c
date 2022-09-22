#include <stdio.h>
#include "g.c"
#include "f.c"
void main()
{
	double x;
	scanf("%lf", &x);

	printf("f(x) = %f\n", f(x));
	printf("g(x) = %f\n", g(x));
}
