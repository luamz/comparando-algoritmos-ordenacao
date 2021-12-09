#include<stdio.h>

void resultados(FILE *arquivo, int n, double tempo){

  fprintf(arquivo, "%d, ", n);
  fprintf(arquivo, "%lf", tempo);
  fprintf(arquivo, "\n");

}
