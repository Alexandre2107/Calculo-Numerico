#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime(float **A,int O);

int main()
{
	int O,i,j,k,m;
	float **A,B[10],X[10],Y[10],soma,op,erro;
	printf("Entre com a ordem do sistema: ");
	scanf("%d",&O);
	A=(float**) malloc(sizeof(float*)*O);
	for(i=0;i<O;i++)
		A[i]=(float*)malloc(sizeof(float)*O);
	printf("\nEntre com a matriz dos coeficientes: ");
	for(i=0;i<O;i++)
		for(j=0;j<O;j++)
			scanf("%f",&A[i][j]);
	printf("\nEntre com o vetor dos termos independentes: ");
	for(i=0;i<O;i++)
		scanf("%f",&B[i]);
	for(i=0;i<O;i++)
		X[i]=0;
	imprime(A,O);
	for(m=0;m<10;m++)
	{
			printf("\nResultado: ");
			for(i=0;i<O;i++)
				printf("\n\n%f",X[i]);
		for(i=0;i<O;i++)
		{
			Y[i]=0;
			for(j=0;j<O;j++)
				Y[i]=Y[i]+A[i][j]*X[j];
		}
		soma=0;
		for(i=0;i<O;i++)
		{
			op=B[i]-Y[i];
			soma=soma+op*op;
		}
		erro=sqrt(soma);
		printf("\n\nErro = %f\n",erro);
		for(i=0;i<O;i++)
			Y[i]=X[i];
		for(i=0;i<O;i++)
		{
			soma=0;
			for(j=0;j<O;j++)
				soma=soma+A[i][j]*Y[j];
			soma=soma-A[i][i]*Y[i];
			X[i]=(B[i]-soma)/A[i][i];
		}
	}
}

void imprime(float **A,int O)
{
	int i,j;
	for(i=0;i<O;i++)
	{
		for(j=0;j<O;j++)
			printf("%.2f ",A[i][j]);
		printf("\n");
	}
}
