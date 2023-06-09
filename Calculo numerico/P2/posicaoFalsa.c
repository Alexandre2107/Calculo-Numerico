#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 8

int main()
{
	int i;
	double a,b,f1,f2,ft,fx,x;
	while(1)
	{
		printf("\nDigite os valores de chute inicial: ");
		scanf("%lf%lf",&a,&b);
		f1=pow(M_E,a)-sin(a)-2;
		f2=pow(M_E,b)-sin(b)-2;
		ft=f1*f2;	
		if(ft<0)
			break;
		if(f1==0)
			printf("%lf raiz",a);
		if(f2==0)
			printf("%lf raiz",b);
	}
	for(i=0;i<n;i++)
	{
		if(f1==f2)
		{
			printf("Impossivel divisao por zero\n");
			break;
		}
		f1=pow(M_E,a)-sin(a)-2;
		f2=pow(M_E,b)-sin(b)-2;
		x=((a*f2)-(b*f1))/(f2-f1);
		fx=pow(M_E,x)-sin(x)-2;
		printf("\nx=%lf",x);
		if(fx==0)
		{
			printf("\n%lf e raiz",x);
			break;
		}
		if((f1*fx)<0)
			b=x;
		if((fx*f2)<0)
			a=x;
	}
}
