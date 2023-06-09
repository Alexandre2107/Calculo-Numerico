#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 3

int main()
{
	int i;
	double a, b, f1, f2, ft, fx, x;
	while (1)
	{
		printf("\nDigite os valores de chute inicial: ");
		scanf("%lf%lf", &a, &b);
		f1 = pow(M_E, a) - sin(a) - 2;
		f2 = pow(M_E, b) - sin(b) - 2;
		ft = f1 * f2;
		if (ft < 0)
			break;
		if (f1 == 0)
			printf("%lf raiz", a);
		if (f2 == 0)
			printf("%lf raiz", b);
	}
	for (i = 0; i < n; i++)
	{
		x = (a + b) / 2;
		fx = pow(M_E, x) - sin(x) - 2;
		f1 = pow(M_E, a) - sin(a) - 2;
		f2 = pow(M_E, b) - sin(b) - 2;
		printf("\nf(%.2lf)=%lf", x, fx);
		if (fx == 0)
			break;
		if ((f1 * fx) < 0)
			b = x;
		if ((fx * f2) < 0)
			a = x;
	}
}