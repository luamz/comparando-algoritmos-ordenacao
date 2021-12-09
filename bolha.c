#include <stdio.h>
#define N 7

void bolha(int A[], int n)
{
	int chave = 1;
	int temp;
	while (chave == 1){
		chave = 0;
		{
			for 
			if (A[i + 1] < A[i]){
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				for (int i = 0; i < n - 1; i++)chave = 1;
			}
		}
	}
}

void imprimeVetor(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int A[] = {64, 34, 25, 12, 22, 11, 90};
	imprimeVetor(A, N);
	bolha(A, N);
	printf("Vetor ordenado: \n");
	imprimeVetor(A, N);
	return 0;
}