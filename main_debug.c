#include<stdio.h>
#include "metodos/bolha.c"
#include "metodos/caixas.c"
#include "metodos/merge.c"
#include "metodos/insertion.c"
#include "util.c"

int main(){
    
  double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;
  
  FILE *arqBolha = fopen("resultados/bolha.txt", "w");
  double tempo_bolha;

  FILE *arqCaixas = fopen("resultados/caixas.txt", "w");
  double tempo_caixas;

  FILE *arqMerge = fopen("resultados/merge.txt", "w");
  double tempo_merge;

  FILE *arqInsertion = fopen("resultados/insertion.txt", "w");
  double tempo_insertion;

  for (int n=2 ; n<5 ; n=n+1){
      tempo_bolha = tempo_caixas = tempo_merge = tempo_insertion = 0;
      gera_sequencias(n);

      printf("\n-------------- N %d --------------", n);
      int *vetor= (int*)malloc(sizeof(int)*n);
      for (int nSeq = 1; nSeq < 10; nSeq++){
        
        vetor = leSequencia(nSeq, n);
        printf("\n-------------- Vetor desordenado - Sequência %d -------------", nSeq);
        imprimeVetor(vetor,n);
        printf("\n--------------");

        printf("\n-------------- Vetor desordenado - Bolha - Sequência %d -------------", nSeq);
        vetor = leSequencia(nSeq, n);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        bolha(vetor,n);
        printf("\n-------------- Vetor ordenado - Bolha - Sequência %d -------------", nSeq);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_bolha += s_CPU_final - s_CPU_inicial;

        printf("\n-------------- Vetor desordenado - Caixas - Sequência %d -------------", nSeq);
        vetor = leSequencia(nSeq, n);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        caixas(vetor,n);
        printf("\n-------------- Vetor ordenado - Caixas - Sequência %d -------------", nSeq);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_caixas += s_CPU_final - s_CPU_inicial;

        printf("\n-------------- Vetor desordenado - Merge - Sequência %d -------------", nSeq);
        vetor = leSequencia(nSeq, n);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        mergeSort(vetor, 0, n - 1);
        printf("\n-------------- Vetor ordenado - Merge - Sequência %d -------------", nSeq);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_merge += s_CPU_final - s_CPU_inicial;
        
        printf("\n-------------- Vetor desordenado - Insertion - Sequência %d -------------", nSeq);
        vetor = leSequencia(nSeq, n);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        insertion(vetor, n);
        printf("\n-------------- Vetor ordenado - Insertion - Sequência %d -------------", nSeq);
        imprimeVetor(vetor,n);
        printf("\n--------------");
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_insertion += s_CPU_final - s_CPU_inicial;
        free(vetor);

      }
      escreve_resultado(arqBolha,n,tempo_bolha);
      escreve_resultado(arqCaixas,n,tempo_caixas);
      escreve_resultado(arqMerge,n,tempo_merge);
      escreve_resultado(arqInsertion,n,tempo_insertion);
      printf("\n-------------- Fim N %d --------------", n);
      
  }
  
  fclose(arqBolha);
  fclose(arqCaixas);
  fclose(arqMerge);
  fclose(arqInsertion);
}
