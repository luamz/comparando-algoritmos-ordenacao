#include <stdio.h>

void insertion(int A[], int n){
  int i, j, temp;
  for (i = 1; i < n; i++){
     temp = A[i]; 
      j = i-1; 
      while (j >= 0 && A[j] > temp){
          A[j+1] = A[j];
          j--;
      }
      A[j+1] = temp;
   }
}

