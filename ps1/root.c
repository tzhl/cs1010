#include <stdio.h>
#include <math.h>

double get_root(double a, double b, double c);

int main(void) {

	double a, b, c, root;

	printf("Enter coefficients (a b c): ");
   scanf("%lf%lf%lf",&a,&b,&c);
   
	root = get_root(a, b, c);

	printf("Bigger root is %.2f\n", root);

	return 0;
}

// Take three coefficients and return the bigger root
double get_root(double a, double b, double c) {

	return (-b+sqrt(b*b-4*a*c))/2/a; // stub, to be replaced by your code 
}
