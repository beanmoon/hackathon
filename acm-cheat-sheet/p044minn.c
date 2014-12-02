#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node_t{
  int sum;
  int b;
}node_t;

int cmp_node(const node_t *left, const node_t *right){
  int result = left->sum - right->sum;
  if(result < 0)
    return -1;
  else if(result > 0)
    return 1;
  else 
    return 0;
}

typedef node_t heap_elem_t;
#include "p039heap.c"

#define MAXN 100
int n;
int a[MAXN], b[MAXN];

void k_merge(){
heap_t *h = heap_create(MAXN, cmp_node);
int i;
node_t tmp;
qsort(a, n, sizeof(int), cmp_int);
qsort(b, n, sizeof(int), cmp_int);
for(i = 0; i < n; i++){
tmp.sum = a[i] + b[0];
tmp.b = 0;
heap_push(h, tmp);
}

for(i = 0; i < n; i++){
heap_elem_t top = heap_pop(h);
printf("%d ", top.sum);
top.sum = top.sum - b[top.b] + b[top.b + 1];
top.b += 1;
heap_push(h, top);
}
printf("\n");  
}

/**
 * this method was the my orginal thought about get the minimum n values
 * and it turns out that it doesn't work
 * because it cann't backtrace and just go straight towards the end of array.
 * for example:
 * <<< input
 * 5            
 * 1 3 2 8 9   
 * 6 9 8 22 1
 * >>> output
 * 2 3 4 9 10
 */
void minn(){
int i=0,j=0, k;
qsort(a, n, sizeof(int), cmp_int);
qsort(b, n, sizeof(int), cmp_int);

while(k<n){
printf("%d ", a[i]+b[j]);
if(a[i] + b[j+1] < a[i+1] + b[j])
  j++;
 else
   i++;
k++;
}
printf("\n");
}
int main() {
int i = 0;
scanf("%d", &n);
for(i = 0; i < n; i++){
scanf("%d", &a[i]);
}
for(i = 0; i < n; i++){
scanf("%d", &b[i]);
}

k_merge();
/* minn(); */
}
