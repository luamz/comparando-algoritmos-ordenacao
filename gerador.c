#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void gera_sequencias(int n){
    int num = 1;
    char nome[8];
    srand(time(NULL));
        for (int j = 0 ; j < 10 ; j++){
          FILE *arquivo;
          sprintf(nome, "%d", num);
          strcat(nome, ".txt");
          arquivo = fopen(nome,"w");
            for (int k=0 ; k<n ; k++){
                fprintf(arquivo, "%d,", rand()%1000);
            }
          fprintf(arquivo, "\n");
          fclose(arquivo);
          num += 1;
        }
}
int main(){
    gera_sequencias(100);
    
}