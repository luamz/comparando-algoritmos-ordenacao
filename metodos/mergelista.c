#include <stdio.h>
#include <stdlib.h>

struct lista{
  int num;
  struct lista *prox;
};

typedef struct lista li;

li *merge(li *lista1, li *lista2){
  if(lista1 == NULL){
    return lista2;
  }else if(lista2 == NULL){
    return lista1;
  }else{
    if(lista1->num <= lista2->num){
      lista1 = merge(lista1->prox, lista2);
      return lista1;
    }else{
      lista2 = merge(lista1, lista2->prox);
      return lista2;
    }
  }
}

li *split(li *lis){
  li *list = NULL;
  if(lis == NULL){
    return NULL;
  }else{
    if(lis->prox == NULL){
      return NULL;
    }else{
      list = lis->prox;
      lis->prox = list->prox;
      list->prox = split(list->prox);
      return list;
    }
  }
}

void mergeSort(li *lista1){
  li *lista2 = NULL;
  if((lista1 != NULL) && (lista1->prox != NULL)){
    lista2 = split(lista1);
    mergeSort(lista1);
    mergeSort(lista2);
    lista1 = merge(lista1, lista2);
  }
}

void imprime(li *L){
  while(L != NULL){
    printf("%d\n", L->num);
    L = L -> prox;
  }
}

int main(){
  int n;
  li *lista = NULL;
  li *novo = NULL;

  printf("Elemento: ");
  scanf("%d", &n);
  while(n >= 0){
    novo = (li*)malloc(sizeof(li));
    novo->num = n;
    novo->prox = lista;
    lista = novo;
    printf("Elemento: ");
    scanf("%d", &n);
  }

  mergeSort(lista);
}