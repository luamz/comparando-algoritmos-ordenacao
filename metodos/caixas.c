#include <stdio.h>

void caixas(int A[], int n)
{
    int min = A[0];
    int max = A[0];
    for (int i = 0; i < n; i++)
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
    
    for (int j = 0; j < n; j++)
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