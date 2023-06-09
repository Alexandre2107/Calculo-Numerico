#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i, j, n;
	float x[10], f[10], soma1, soma2, soma, p;
	
	printf("Entre com a quantidade de pontos: ");
	scanf("%d", &n);
	printf("Entre com os pontos conhecidos:\n");
	for(i = 0; i <= n-1; i++){
		printf("x[%d] = ", i);
		scanf("%f", &x[i]);
		printf("f[x[%d]] = ", i);
		scanf("%f", &f[i]);
	}
	printf("\nEntre com um pontopara ser avaliado: ");
	scanf("%f", &p);
	
	soma = 0;
	for(i = 0; i <= n-1; i++){
		soma1 = 1; soma2 = 1;
		for(j = 0; j <= n-1; j++){
			if(j != i){
				soma1 = soma1 * (p-x[j]);
				soma2 = soma2 * (x[i]-x[j]);
			}
		}
		soma = soma + f[i]*(soma1/soma2);	
	}
	printf("f(%.1f) =  %.3f", p, soma);
	
}
