#include <stdio.h>
#include <stdlib.h>

int main(){
  int M = 10;
  int *lps = malloc(sizeof(int)*M);
  lps[0] = 12;
  printf("%d\n", lps[0]);
  //  printf("%d\n", strlen("hello"));
}
