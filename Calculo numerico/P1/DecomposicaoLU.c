#include <stdio.h>
#include <stdlib.h>

void libera(float **m,int n);

int main()
{
	int i,n,j,k;
	float a[10][10],b[10],x[10],y[10],**id,soma,mult,aux[10];
	printf("Entre com a ordem do sistema: ");
	scanf("%d",&n);
	id=(float**)malloc(n*sizeof(float*));
	for(i=0;i<n;i++)
		id[i]=(float*)malloc(n*sizeof(float));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				id[i][j]=1;
			else
				id[i][j]=0;
		}
	}
	printf("\nEntre com a matriz dos coeficientes: ");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%f",&a[i][j]);
	printf("\nEntre com o vetor dos termos independentes: ");
	for(i=0;i<n;i++)
		scanf("%f",&b[i]);
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			mult=-((a[j][i])/a[i][i]);
			a[j][i]=0;
			for(k=i+1;k<=n;k++)
			{
				a[j][k]=a[j][k]+mult*a[i][k];
				id[j][k-1]=id[j][k-1]+mult*id[i][k-1];
			}
			b[j]=b[j]+mult*b[i];
		}
	}
	for(i=0;i<=n-1;i++)
	{
		soma=0;
		for(j=i+1;j<=n-1;j++)
			soma+=id[i][j]*y[j];
		y[i]=(b[i]-soma)/id[i][i];
	}
	for(i=n-1;i>=0;i--)
	{
		soma=0;
		for(j=i+1;j<=n-1;j++)
			soma+=a[i][j]*x[j];
		x[i]=(y[i]-soma)/a[i][i];
	}
	printf("\nResposta:\n\n");
	for(i=0;i<n;i++)
		printf("%.2f ",x[i]);
	libera(id,n);
}

void libera(float **m,int n)
{
	int i;
	for(i=0;i<n;i++)
		free(m[i]);
	free(m);
}
