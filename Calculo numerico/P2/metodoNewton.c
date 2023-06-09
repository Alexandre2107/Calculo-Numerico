#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 8

int main()
{
	int i;
	double a,f1,f2;
	while(1)
	{
		printf("\nDigite o valor de chute inicial: ");
		scanf("%lf",&a);
		f1=pow(M_E,a)-sin(a)-2;
		f2=pow(M_E,a)-cos(a);
		if(f1==0)
		{
			printf("%lf e raiz",a);
			exit(0);
		}
		if(f2==0)
			printf("\nImpossivel divisao por zero");
		else
		{
			for(i=0;i<nite;i++)
			{
				a=a-(f1/f2);
				printf("\nx=%lf",a);
				f1=pow(M_E,a)-sin(a)-2;
				f2=pow(M_E,a)-cos(a);
			}
			break;
		}
	}
}
