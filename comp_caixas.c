#include <stdio.h>
#include "metodos/bolha.c"
#include "metodos/caixas.c"
#include "metodos/merge.c"
#include "metodos/insertion.c"
#include "util.c"

void executa_caixas(FILE *arqCaixas, double tempo_caixas, 
                    double s_CPU_inicial, double s_CPU_final, 
                    double s_total_inicial, double s_total_final,
                    int max, int passo, int semente){
    for (int n = 10; n < max; n = n + passo)
    {
    progresso("Executando... ", n, max);
    tempo_caixas = 0;
    gera_sequencias(n, semente);

    int *vetor = (int *)malloc(sizeof(int) * n);

    for (int nSeq = 1; nSeq < 11; nSeq++)
    {
      vetor = leSequencia(nSeq, n);
      Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);
      caixas(vetor, n);
      Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);
      tempo_caixas += s_CPU_final - s_CPU_inicial;
    }

    free(vetor);
    escreve_resultado(arqCaixas, n, tempo_caixas);
  }

}


int main()
{

  double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;

  FILE *arqCaixas1 = fopen("resultados/comp_caixas/caixas1.txt", "w");
  double tempo_caixas1;

  FILE *arqCaixas2 = fopen("resultados/comp_caixas/caixas2.txt", "w");
  double tempo_caixas2;

  FILE *arqCaixas3 = fopen("resultados/comp_caixas/caixas3.txt", "w");
  double tempo_caixas3;

  FILE *arqCaixas4 = fopen("resultados/comp_caixas/caixas4.txt", "w");
  double tempo_caixas4;

  FILE *arqCaixas5 = fopen("resultados/comp_caixas/caixas5.txt", "w");
  double tempo_caixas5;

  int passo = 1000;
  int max = 100000;

  executa_caixas(arqCaixas1,tempo_caixas1,s_CPU_inicial,
  s_CPU_final,s_total_inicial,s_total_final,max,passo,1000);

  executa_caixas(arqCaixas2,tempo_caixas2,s_CPU_inicial,
  s_CPU_final,s_total_inicial,s_total_final,max,passo,10000);

  executa_caixas(arqCaixas3,tempo_caixas3,s_CPU_inicial,
  s_CPU_final,s_total_inicial,s_total_final,max,passo,50000);

  executa_caixas(arqCaixas4,tempo_caixas4,s_CPU_inicial,
  s_CPU_final,s_total_inicial,s_total_final,max,passo,100000);

  executa_caixas(arqCaixas5,tempo_caixas5,s_CPU_inicial,
  s_CPU_final,s_total_inicial,s_total_final,max,passo,1000000);
  
  fclose(arqCaixas1);
  fclose(arqCaixas2);
  fclose(arqCaixas3);
  fclose(arqCaixas4);
  fclose(arqCaixas5);

  printf("\033[92m Concluído     [=======================================================]  100%%\n");
}
