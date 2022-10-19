#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double atof(const char *string);

void resolve(double a, double b, double c){
	double d = pow(b, 2) - 4 * a * c, x1, x2;

	if (d < 0) 
	{
		printf("No solution!\n");
	} 
	else if (d == 0) 
	{
		x1 = -b / (2 * a);
		x2 = -b / (2 * a);

		printf("x = %.4lf\n", x1);
	} 
	else 
	{
		x1 = (-b + sqrt(d))/(2 * a);
		x2 = (-b - sqrt(d))/(2 * a);

		printf("x1 = %.4lf\nx2 = %.2lf\n", x1, x2);
	}
}

int main(int argc, char *argv[]){
	int i;
	char abc[3] = "abc";

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

	printf("%.4lf * x^2 + %.4lf * x + %.4lf = 0\n\n", a, b, c);

    resolve(a, b, c);
}
