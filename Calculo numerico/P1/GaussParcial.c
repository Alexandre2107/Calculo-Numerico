#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,n,j,k,l;
	float a[10][10],b[10],x[10],soma,mult,aux,maior;
	printf("Entre com a ordem do sistema: ");
	scanf("%d",&n);
	printf("\nEntre com a matriz dos coeficientes: ");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%f",&a[i][j]);
	printf("\nEntre com o vetor dos termos independentes: ");
	for(i=0;i<n;i++)
		scanf("%f",&b[i]);
	for(i=0;i<(n-1);i++)
	{
		maior=a[i][i];
		l=i;
		for(k=i+1;k<n;k++)
		{
			if(abs(a[k][i])>abs(maior) || maior==0)
			{
				maior=a[k][i];
				l=k;
			}
		}
		if(l!=i)
		{
			for(k=i;k<n;k++)
			{
				aux=a[i][k];
				a[i][k]=a[l][k];
				a[l][k]=aux;
			}
				aux=b[i];
				b[i]=b[l];
				b[l]=aux;
		}
		for(k=0;k<n;k++)
		{
			for(j=0;j<n;j++)
				printf("%.2f ",a[k][j]);
			printf("\n");
		}
		for(j=i+1;j<n;j++)
		{
			mult=-((a[j][i])/a[i][i]);
			a[j][i]=0;
			for(k=i+1;k<n;k++)
				a[j][k]=a[j][k]+mult*a[i][k];
			b[j]=b[j]+mult*b[i];
		}
	}
	for(i=n-1;i>=0;i--)
	{
		soma=0;
		for(j=i+1;j<=n-1;j++)
			soma+=a[i][j]*x[j];
		x[i]=(b[i]-soma)/a[i][i];
	}
	printf("\nResposta:\n\n");
	for(i=0;i<n;i++)
		printf("%.2f ",x[i]);
}
