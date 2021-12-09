#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



void gera_sequencias(int n){
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
                fprintf(arquivo, "%d,", rand()%1000);
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