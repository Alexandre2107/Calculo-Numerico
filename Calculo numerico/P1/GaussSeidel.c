#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int O,i,j,k,m; //O=ordem do sistema; i=contador; j=contador k=contador
	float **A,*B,*X,*Y,soma,ope,erro;
	
	printf("Entre com a ordem do sistema: ");
	scanf("%d",&O);
	
	A=(float**) malloc(sizeof(float*)*O);//malloc da matriz dos coeficientes
	for(i=0;i<O;i++){
		A[i]=(float*) malloc(sizeof(float)*O);
	}
	printf("Entre com a matriz dos coeficientes:\n");
	for(i=0;i<O;i++){//preenche a matriz dos coeficientes
		for(j=0;j<O;j++){
			scanf("%f",&A[i][j]);
		}
	}
	B=(float*) malloc(sizeof(float)*O);
	X=(float*) malloc(sizeof(float)*O);
	Y=(float*) malloc(sizeof(float)*O);
	printf("Entre com o vetor dos termos independentes:\n");
	for(i=0;i<O;i++){
		scanf("%f",&B[i]);
	}
	
	for(i=0;i<O;i++){//primeira iteração chute inicial
		X[i]=0;
	}
	
	printriz(A,O);//printa a matriz dos coeficientes
	for(m=0;m<10;m++){
		printf("\nResultado:");
	for(i=0;i<O;i++){
			printf("\n%f",X[i]);
	}
	for(i=0;i<O;i++){// X - iteracão , Y = A.X
		Y[i]=0;
		for(j=0;j<O;j++){
			Y[i]=Y[i]+A[i][j]*X[j];
		}
	}
	soma=0;
	for(i=0;i<O;i++){
		ope=B[i]-Y[i];
		soma=soma+ope*ope;
	}
	erro=sqrt(soma);
	printf("\nErro=%f\n",erro);
	
	for(i=0;i<O;i++){
		soma=0;
		for(j=0;j<O;j++){
			soma=soma+A[i][j]*X[j];
		}
		soma=soma-A[i][i]*X[i];
		X[i]=(B[i]-soma)/A[i][i];
	}
}
}

printriz(float **A,int O){//printa a matriz dos coeficientes
	int i,j;
	for(i=0;i<O;i++){
		for(j=0;j<O;j++){
			printf("%.2f ",A[i][j]);
		}
		printf("\n");
	}
	
}

