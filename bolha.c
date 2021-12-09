#include <stdio.h>
#define N 7

void imprimeVetor(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void bolha(int A[], int n)
{
	int chave = 1;
	int temp;
	while (chave == 1){
		chave = 0;
		{
			for (int i = 0; i < n - 1; i++){
				if (A[i + 1] < A[i]){
					temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
					chave = 1;
				}	
			}	
		}
	}
}



int main()
{
	int A[] = {64, 34, 25, 12, 22, 11, 90};
	imprimeVetor(A, N);
	bolha(A, N);
	imprimeVetor(A, N);
	return 0;
}