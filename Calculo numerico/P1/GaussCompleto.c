#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, j, k, flag = 0;
	float A[10][10], b[10], x[10], soma, op;
	float testeFuncao;
	int i2, j2, l, c, i3, f = 0;
	printf("Entre com a ordem do sistema\n");
	scanf("%d", &n);

	int *posicao;
	posicao = (int)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		posicao[i] = i;
	printf("Entre com a matriz dos coeficientes\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%f", &A[i][j]);
	printf("Entre com o vetor dos termos independentes\n");
	for (i = 0; i < n; i++)
		scanf("%f", &b[i]);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}

	for (i = 0; i < n - 1; i++)
	{
		testeFuncao = A[i][i];
		l = i;
		c = i;
		for (i2 = i; i2 < n; i2++)
			for (j2 = i; j2 < n; j2++)
				if (abs(A[i2][j2]) > abs(testeFuncao) || testeFuncao == 0)
				{
					testeFuncao = A[i2][j2];
					l = i2;
					c = j2;
					f = 1;
				}

		if (l != i)
		{
			for (i3 = i; i3 < n; i3++)
			{
				testeFuncao = A[i][i3];
				A[i][i3] = A[l][i3];
				A[l][i3] = testeFuncao;
			}
			testeFuncao = b[i];
			b[i] = b[l];
			b[l] = testeFuncao;
		}

		if (c != i)
		{
			for (i3 = 0; i3 < n; i3++)
			{
				testeFuncao = posicao[c];
				posicao[c] = posicao[i];
				posicao[i] = testeFuncao;

				testeFuncao = A[i3][i];
				A[i3][i] = A[i3][c];
				A[i3][c] = testeFuncao;
			}
		}

		flag = 0;

		for (j = i + 1; j < n; j++)
		{
			op = -A[j][i] / A[i][i];
			b[j] = b[j] + (b[i] * op);
			for (k = i; k <= n; k++)
			{
				A[j][k] = A[j][k] + (A[i][k] * op);
			}
		}
	}

	printf("\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}

	for (i = n - 1; i >= 0; i--)
	{
		soma = 0;
		for (j = (i + 1); j <= (n - 1); j++)
			soma += A[i][j] * x[j];
		x[i] = (b[i] - soma) / A[i][i];
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (posicao[j] == i)
				printf("%.2f\n", x[j]);
	return 0;
}
