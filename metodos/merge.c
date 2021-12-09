#include <stdio.h>
#include <stdlib.h>

void mergea(int A[], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
  
    int p1[n1],p2[n2];
  
    for (i = 0; i < n1; i++)
        p1[i] = A[inicio + i];
    for (j = 0; j < n2; j++)
       p2[j] = A[meio + 1 + j];
  
    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (p1[i] <=p2[j]) {
            A[k] = p1[i];
            i++;
        }
        else {
            A[k] =p2[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        A[k] = p1[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        A[k] =p2[j];
        j++;
        k++;
    }
}

void merge(int A[], int inicio, int fim)
{
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge(A, inicio, meio);
        merge(A, meio + 1, fim);
  
        mergea(A, inicio, meio, fim);
    }
}