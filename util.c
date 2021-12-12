#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/resource.h>


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



void gera_sequencias(int n, int semente){
    int num = 1;
    char nome[8];
    srand(time(NULL));
        for (int j = 0 ; j < 10 ; j++){
          char path[20] = "sequencias/seq";
          FILE *arquivo;
          sprintf(nome, "%d", num);
          strcat(nome, ".txt");
          strcat(path,nome);
          arquivo = fopen(path,"w");
            for (int k=0 ; k<n ; k++){
                fprintf(arquivo, "%d,", rand()%semente);
            }
          fprintf(arquivo, "\n");
          fclose(arquivo);
          num += 1;
        }
}

int *leSequencia(int nSeq, int n){
    FILE *arq;
    char c[n];
    int *vetor  = malloc(sizeof(int) * n); 
    char path[20] = "sequencias/seq";
    char nome[8];
    sprintf(nome, "%d", nSeq);
    strcat(nome, ".txt");
    strcat(path,nome);

    if (arq = fopen(path, "r")) {
        for (int i =0; i<n ; i++){
            fscanf(arq, "%d,", &vetor[i] ); 
        }
        fclose(arq);
    }

    else {
        printf("Error! Arquivo não existe.");
        exit(1);
    }

    return vetor;
}

void escreve_resultado(FILE *arquivo, int n, double tempo){

  fprintf(arquivo, "%d, ", n);
  fprintf(arquivo, "%lf", tempo);
  fprintf(arquivo, "\n");

}

void imprimeVetor(int A[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void progresso( char label[], int n, int total )
{
    
    int tamanho = 70 - strlen( label );
    int pos = ( n * tamanho ) / total ;    
    int porcentagem = ( n * 100 ) / total;

    printf( "\033[93m %s[", label );
    for ( int i = 0; i < pos; i++ )
      printf( "%c", '=' );
    printf("] %d%%\n", porcentagem );

}