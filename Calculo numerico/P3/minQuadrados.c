#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int numero, i, j, k, l, m, linha, ordem;
	printf("Digite o numero de pontos (x): ");
	scanf("%d",&numero);
	float matriz[3][3], vetor[3], x[3], xis[numero], fx[numero], xquadrado[numero], x3[numero], x4[numero], xfx[numero], somatorio1 = 0, somatorio2 = 0, somatorio3 = 0, somatorio4 = 0,  somatorio5= 0, somatorio6 = 0, somatorio7 = 0, somatorio8 = 0, soma, result, resposta, multiplicador, maior, aux;
	for(i=1;i<=numero;i++){
		printf("x: ", i);
		scanf("%f",&xis[i]);
		printf("f(x): ", i);
		scanf("%f",&fx[i]);
		somatorio2 = somatorio2 + xis[i];
		somatorio4 = somatorio4 + fx[i];
	}
	for(i=1;i<=numero;i++){
		xquadrado[i] = pow(xis[i],2);
		somatorio1 = somatorio1 + xquadrado[i];
		x3[i] = pow(xis[i],3);
		somatorio6 = somatorio6 + x3[i];
		x4[i] = pow(xis[i],4);
		somatorio7 = somatorio7 + x4[i];
	}
	
	for(i=1;i<=numero;i++){
		somatorio3 = somatorio3 + xis[i] * fx[i];
		somatorio8 = somatorio8 + xquadrado[i]  * fx[i];
		somatorio5 = somatorio5 + 1;
	}
	
	matriz[1][1] = somatorio7;
	matriz[1][2] = somatorio6;
	matriz[1][3] = somatorio1;
	matriz[2][1] = somatorio6;
	matriz[2][2] = somatorio1;
	matriz[2][3] = somatorio2;
	matriz[3][1] = somatorio1;
	matriz[3][2] = somatorio2;
	matriz[3][3] = somatorio5;
	vetor[1] = somatorio8;
	vetor[2] = somatorio3;
	vetor[3] = somatorio4;
	printf("\nMATRIZ:\n\n");
	
	for(i=1;i<=3;i++){
		for(j=1;j<4;j++){
			printf("%10f", matriz[i][j]);
		}
		printf("%10f\n", vetor[i]);
	}
	
	ordem = 3;
	for(i=1;i<=ordem-1;i++){
		maior = matriz[i][i];
		linha = i;
		
		for(l=i+1;l<=ordem;l++){
			if(abs(maior) < abs(matriz[l][i])){
				maior = matriz[l][i];
				linha = l;
			}
		}
		for(m=1;m<=ordem;m++){
			aux = matriz[i][m];
			matriz[i][m] = matriz[linha][m];
			matriz[linha][m] = aux;
		}
			aux = vetor[i];
			vetor[i] = vetor[linha];
			vetor[linha] = aux;
				
		for(j=i+1;j<=ordem;j++){
			multiplicador = - (matriz[j][i]) / matriz [i][i];
			matriz[j][i] = 0;
			for(k=i+1;k<=ordem;k++){
				matriz[j][k] = (matriz[i][k] * multiplicador) + matriz [j][k];
			}
			vetor[j] = vetor[i] * multiplicador + vetor[j];
		}
	}

	for(i=ordem;i>=1;i--){
		soma = 0;
		for(j=i+1;j<=ordem;j++){
			soma = soma + ( matriz[i][j] * x[j] );
		}
		x[i] = (vetor[i] - soma)/ matriz[i][i];
	}
	
	printf("\n");
	printf("Digite o ponto para achar a funcao: ");
	scanf("%f", &result);
	printf("\n");
	resposta = x[1]*pow(result,2) + x[2]*result + x[3];
	printf("Polinomio = [%.2f x^2] + [%.2f x] + [%.2f]\nF(%.3f) = %f", x[1], x[2], x[3], result, resposta);
	
	return 0;
}
