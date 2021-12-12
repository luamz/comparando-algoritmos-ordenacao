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

  for (int n= 10; n<100000 ; n=n+10){
        progresso("Executando... ",n,100000);
        tempo_bolha = 0;
        tempo_caixas = 0;
        tempo_merge = 0;
        tempo_insertion = 0;

        gera_sequencias(n);
        
        int *vetor= (int*)malloc(sizeof(int)*n);

        for (int nSeq = 1; nSeq < 10; nSeq++){
        vetor = leSequencia(nSeq, n);
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        bolha(vetor,n);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_bolha += s_CPU_final - s_CPU_inicial;

        vetor = leSequencia(nSeq, n);
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        caixas(vetor,n);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_caixas += s_CPU_final - s_CPU_inicial;

        vetor = leSequencia(nSeq, n);
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        merge(vetor, 0, n - 1);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_merge += s_CPU_final - s_CPU_inicial;
        
        vetor = leSequencia(nSeq, n);
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        insertion(vetor, n);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_insertion += s_CPU_final - s_CPU_inicial; 

        }

        free(vetor);
        escreve_resultado(arqBolha,n,tempo_bolha);
        escreve_resultado(arqCaixas,n,tempo_caixas);
        escreve_resultado(arqMerge,n,tempo_merge);
        escreve_resultado(arqInsertion,n,tempo_insertion);
  }
  
  fclose(arqBolha);
  fclose(arqCaixas);
  fclose(arqMerge);
  fclose(arqInsertion);
  printf("\033[92m Concluído     [=======================================================]  100%%\n");
}
