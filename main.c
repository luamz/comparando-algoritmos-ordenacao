#include<stdio.h>
#include <unistd.h> 
#include <sys/resource.h>
#include "bolha.c"
#include "caixas.c"
#include "gerador.c"
#include "merge.c"
#include "insertion.c"

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
  long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
  struct rusage ptempo;

  getrusage(0,&ptempo);

  seg_CPU = ptempo.ru_utime.tv_sec;
  mseg_CPU = ptempo.ru_utime.tv_usec;
  seg_sistema = ptempo.ru_stime.tv_sec;
  mseg_sistema = ptempo.ru_stime.tv_usec;

 *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
 *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}

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

    for (int n=10 ; n<1000 ; n=n+10){
      tempo_bolha = tempo_caixas = tempo_insertion = tempo_insertion = 0;
      int *vetor= (int*)malloc(sizeof(int)*n);
      gera_sequencias(n);
      for (int nSeq = 1; nSeq < 6; nSeq++){

        vetor = leSequencia(nSeq, n);

        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        bolha(vetor,n);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_bolha += s_CPU_final - s_CPU_inicial;

  
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        caixas(vetor,n);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_caixas += s_CPU_final - s_CPU_inicial;


        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        merge(vetor, 0, n - 1);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_merge += s_CPU_final - s_CPU_inicial;
        
        Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
        insertion(vetor, n);
        Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
        tempo_merge += s_CPU_final - s_CPU_inicial;

      }
      escreve_resultado(arqBolha,n,tempo_bolha);
      escreve_resultado(arqCaixas,n,tempo_caixas);
      escreve_resultado(arqMerge,n,tempo_merge);
      escreve_resultado(arqInsertion,n,tempo_insertion);
    }

}
