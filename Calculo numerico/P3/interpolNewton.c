#include<stdio.h>
#include<stdlib.h>

int main(){
	float matriz[20][20], m, x[20], fx[20], resposta, resposta2;
	int i, j, qtd;
	printf("Quantos numeros? (x): ");
	scanf("%d",&qtd);
	for(i=0;i<qtd;i++){
		printf("\nx: ");
		scanf("%f",&x[i]);
		printf("\nf(x): ");
		scanf("%f",&fx[i]);
	}

	for(i=0;i<qtd;i++){
		for(j=0;j<=qtd;j++){
			matriz[i][j] = 0;
		}
	}
	
	j=0;
	for(i=0;i<qtd;i++){
		matriz[i][j] = x[i];
	}
	j=1;
	for(i=0;i<qtd;i++){
		matriz[i][j] = fx[i];
	}
	
	for(i=0;i<qtd;i++){
		for(j=2;j<=qtd;j++){
			if(i+1 >= j){
				matriz[i][j] = ((matriz[i][j-1] - matriz[i-1][j-1]) / (matriz[i][0] - matriz[i+1-j][0]));
			}
		}
		
	}
			
	printf("\nTabela:\n\n");
	for(i=0;i<qtd;i++){
		for(j=0;j<=qtd;j++){
			printf("%9f ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nDigite o ponto para achar a funcao: ");
	scanf("%f", &m);
	
	resposta = matriz[0][1];
	for(i=0;i<qtd-1;i++){
		resposta2 = 1;
		for(j=0;j<i;j++){
			resposta2 = resposta2 * (m - matriz[i][0]);
		}
			resposta2 = resposta2 * (matriz[j+1][j+2]) * (m - matriz[0][0]);
			resposta = resposta + resposta2;
	}
	
	printf("F(%.1f) = %f",m, resposta);
	return 0;
}
