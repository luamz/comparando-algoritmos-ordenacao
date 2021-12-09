#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void gera_sequencias(int n){
    FILE *arquivo;
    arquivo = fopen("sequencias.txt","w");

    srand(time(NULL));
        for (int j = 0 ; j < 10 ; j++){
            for (int k=0 ; k<n ; k++){
                fprintf(arquivo, "%d,", rand()%1000);
        }
        fprintf(arquivo, "\n");
    }
}
int main(){
    gera_sequencias(100);
    
}