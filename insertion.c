#include <stdio.h>
#define N 7

void imprimeVetor(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}


void insertion(int A[], int n){
  int i, j, temp;
  for (i = 1; i < n; i++){
     temp = A[i]; 
      j = i-1; 
      while (j >= 0 && A[j] > temp){
          A[j+1] = A[j];
          j--;
      }
      A[j+1] = temp;
   }
}


int main() {
 
  int A[] = {64, 34, 25, 12, 22, 11, 90};

  imprimeVetor(A, N);
  insertion(A, N);
  imprimeVetor(A,N);
  
  return 0;
}