#include <stdio.h>
#define N 7

void imprimeVetor(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void caixas(int A[])
{
    int min = A[0];
    int max = A[0];
    for (int i = 0; i < N; i++)
    {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    int qtd_caixas = max - min;
    int caixas[qtd_caixas];

    for (int i = 0; i < qtd_caixas; i++)
    {
        caixas[i] = 0;
    }
    for (int j = 0; j < N; j++)
    {
        caixas[A[j] - min]++; // Posição relativa número-min
    }

    int temp = 0;
    for (int k = 0; k < qtd_caixas; k++)
    {
        while (caixas[k])
        {
            A[temp] = k + min;
            caixas[k]--;
            temp++;
        }
    }
}

int main()
{

    int A[] = {64, 34, 25, 12, 22, 11, 90};
    imprimeVetor(A, N);
    caixas(A);
    imprimeVetor(A, N);

    return 0;
}
