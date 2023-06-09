#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	float *v, *fv, numerofx;
	
	int grau, i, j, k, l, m, gr, linha;
	float matriz[10][10], vetor[10], x[10], soma, multiplicador, maior, aux, resultadinho = 0;
	
	printf("Grau do polinomio: ");
	scanf("%d", &grau);
	
	v = malloc(sizeof(int) * grau);
	fv = malloc(sizeof(int) * grau);
	
	for(i = 1; i <= grau; i++){
		printf("\nEntre com o numero (X%d): ", i);
		scanf("%f", &v[i]);
		
		printf("\nEntre com a funcao do numero (F(%d)): ", v[i]);
		scanf("%f", &fv[i]);
	}
	
	for(i=1;i<=grau;i++){
		gr = grau;
		for(j=1;j<=grau;j++){
			matriz[i][j] = pow(v[i],gr-1);
			gr--;
		}
		vetor[i] = fv[i];
	}
	
	printf("\nMATRIZ:\n");
	
	for(i=1;i<=grau;i++){
		for(j=1;j<=grau;j++){
			printf("%10f", matriz[i][j]);
		}
		printf("%10f\n",vetor[i]);
	}
		for(i=1;i<=grau-1;i++){
		maior = matriz[i][i];
		linha = i;
		
		for(l=i+1;l<=grau;l++){
			if(abs(maior) < abs(matriz[l][i])){
				maior = matriz[l][i];
				linha = l;
			}
		}
		for(m=1;m<=grau;m++){
			aux = matriz[i][m];
			matriz[i][m] = matriz[linha][m];
			matriz[linha][m] = aux;
		}
			aux = vetor[i];
			vetor[i] = vetor[linha];
			vetor[linha] = aux;
				
		for(j=i+1;j<=grau;j++){
			multiplicador = - (matriz[j][i]) / matriz [i][i];
			matriz[j][i] = 0;
			for(k=i+1;k<=grau;k++){
				matriz[j][k] = (matriz[i][k] * multiplicador) + matriz [j][k];
			}
			vetor[j] = vetor[i] * multiplicador + vetor[j];
		}
	}
		for(i=grau;i>=1;i--){
		soma = 0;
		for(j=i+1;j<=grau;j++){
			soma = soma + ( matriz[i][j] * x[j] );
		}
		x[i] = (vetor[i] - soma)/ matriz[i][i];
	}
	printf("\nP(x)=");
	for(i=grau, j=1;i>0, j<=grau;i--,j++){
		if(i != 1){
			printf(" [%.0f(x^%d)] +", x[j],i-1);
		}else{
			printf(" [%.0f(x^%d)]\n", x[j],i-1);
		}
	}
	printf("Digite o numero que voce quer saber f(x): ");
	scanf("%f",&numerofx);
	gr = grau-1;
	for(i=grau, j=1;i>0, j<=grau;i--,j++){
		resultadinho = resultadinho + (x[j]*pow(numerofx,gr));
		gr--;

	}
	printf("F(%.0f) = %f", numerofx, resultadinho);
	

	
	
}


