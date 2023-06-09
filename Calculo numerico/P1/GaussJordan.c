#include <stdio.h>
#include <stdlib.h>

void imprime(float **A,int O);

int main()
{
	int i,j,k,O,l;
	float **A,B[10],X[10],soma,op;
	printf("Digite a ordem do sistema: ");
	scanf("%d",&O);
	A=(float**)malloc(O*sizeof(float*));
	for(i=0;i<O;i++)
		A[i]=(float*)malloc(O*sizeof(float));	
	printf("\nDigite a matriz dos coeficientes: ");
	for(i=0;i<O;i++)
		for(j=0;j<O;j++)
			scanf("%f",&A[i][j]);
	printf("\nDigite a matriz dos termos independentes: ");
	for(i=0;i<O;i++)
		scanf("%f",&B[i]);
	for(i=0;i<O;i++)
	{
		for(j=0;j<O;j++)
			printf("%.2f ",A[i][j]);
		printf("= %.2f\n",B[i]);
	}	
	for(i=0;i<O;i++)
	{
		for(j=0;j<O;j++)
		{
			if(j!=i)
			{
				op=A[j][i];
				for(k=0;k<O;k++)
					A[j][k]=A[j][k]+(A[i][k]*(-op/A[i][i]));
				B[j]=B[j]+(B[i]*(-op/A[i][i]));
			}
		}
	}
	for(i=O-1;i>=0;i--)
	{
		soma=0;
		for(j=i;j<O;j++)
		{
			soma+=A[i][j]*X[j];
			X[i]=(B[i]-soma)/A[i][i];
		}
	}
	printf("\n");
	imprime(A,O);
	printf("\nResultado:");
	for(i=0;i<O;i++)
			printf("\n\n%.2f",X[i]);
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
