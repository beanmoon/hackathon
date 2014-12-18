#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ufs_t{
  int *p;
  int size;
} ufs_t;

ufs_t* ufs_create(int n){
  ufs_t *ufs = (ufs_t*)malloc(sizeof(ufs_t));
  int *p = malloc(n * sizeof(int));
  for(int i = 0; i<n; i++){
    p[i] = -1;
  }
  ufs->p = p;
  ufs->size = n;
  return ufs;
}


void ufs_destroy(ufs_t *ufs){
  free(ufs->p);
  free(ufs);
}

int ufs_find(ufs_t *ufs, int x){
  if(ufs->p[x] < 0)
    return x;
  return ufs->p[x] = ufs_find(ufs, ufs->p[x]);
}

int ufs_find_naive(ufs_t *ufs, int x){
  while(ufs->p[x] >= 0){
    x = ufs->p[x];
  }
  return x;
}

int ufs_find_iterative(ufs_t *ufs, int x){
  int oldx = x;
  while(ufs->p[x] >= 0){
    x = ufs->p[x];
  }
  while(oldx != x){
    int temp = ufs->p[oldx];
    ufs->p[oldx] = x;
    oldx = temp;
  }
  return x;
}

int ufs_union(ufs_t *ufs, int x, int y){
  int rx = ufs_find(ufs, x);
  int ry = ufs_find(ufs, y);
  if(rx == ry)
    return -1;
  ufs->p[rx] += ufs->p[ry];
  ufs->p[ry] = rx;
  return ufs->p[rx];
}

int ufs_size(ufs_t *ufs, int x){
  int rx = ufs_find(ufs, x);
  return -ufs->p[rx];
}


int main() {

}
