#include <stdio.h>

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
