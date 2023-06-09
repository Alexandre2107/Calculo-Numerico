#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 4

int main()
{
	int i;
	double a,b,f1,f2,x;

	while(1)
	{
		printf("\nDigite os valores de chute inicial: ");
		scanf("%lf%lf",&a,&b);
		f1=pow(M_E,a)-sin(a)-2;
		f2=pow(M_E,b)-sin(b)-2;
		if(f1==0)
		{
			printf("%lf e raiz",a);
			exit(0);
		}
		if(f2==0)
		{
			printf("%lf e raiz",b);
			exit(0);
		}
		if(f2==f1)
			printf("\nImpossivel divisao por zero");
		else
		{
			for(i=0;i<n;i++)
			{
				x=((a*f2)-(b*f1))/(f2-f1);
				printf("\nx=%lf",x);
				a=b;
				b=x;
				f1=pow(M_E,a)-sin(a)-2;
				f2=pow(M_E,b)-sin(b)-2;
			}	
			break;
		}
	}
}
