#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int heap_elem_t;
typedef struct heap_t {
  int size;
  int capacity;
  heap_elem_t *elems;
  int (*cmp)(const heap_elem_t *left, const heap_elem_t *right);
}heap_t;

// why not directly compare the value itself?
int cmp_int(const int *left, const int *right){
  int result = *left - *right;
  if(result < 0)
    return -1;
  else if(result > 0)
    return 1;
  else 
    return 0;
}


heap_t *heap_create(int capacity, 
		    int (*cmp)(const heap_elem_t*, const heap_elem_t*)){
  heap_t *tmp = malloc(sizeof(heap_t));
  tmp->size = 0;
  tmp->capacity = capacity;
  tmp->elems = malloc(tmp->capacity * sizeof(heap_elem_t));
  tmp->cmp = cmp;
  return tmp;
}

void heap_destroy(heap_t *heap){
  free(heap->elems);
  free(heap);
}

int heap_empty(heap_t *heap){
  return heap->size == 0;
}

int heap_size(heap_t *heap){
  return heap->size;
}

void heap_shift_down(heap_t *heap, int start){
  int i = start;
  int j; 
  heap_elem_t tmp = heap->elems[start];
  for(j = 2*i+1; j < heap->size; j = j*2+1){
    if(j < heap->size -1 && heap->cmp(&(heap->elems[j+1]), &(heap->elems[j])) < 0)
      j++;
    if(heap->cmp(&tmp, &(heap->elems[j])) < 0)
      break;
    else{
      heap->elems[i] = heap->elems[j];
      i = j;
    }
  }
  heap->elems[i] = tmp;
}

void heap_shift_up(heap_t *heap, int start){
  int i = start;
  int j = (i - 1) / 2;
  heap_elem_t tmp = heap->elems[start];
  /* while(heap->cmp(&tmp, &(heap->elems[j])) < 0){ */
  /*   heap->elems[i] = heap->elems[j]; */
  /*   i = j; */
  /*   j = (j - 1) / 2; */
  /* } */
  // 当我们到达堆的顶部时，就不应该继续往上走了，这时候的判断临界条件应为i，不是j
  while(i > 0){
    if(heap->cmp(&tmp, &(heap->elems[j])) < 0){
      heap->elems[i] = heap->elems[j];
      i = j;
      j = (j - 1) / 2;
    }else
      break;
  }
  heap->elems[i] = tmp;
}

void heap_push(heap_t *heap, heap_elem_t new){
  if(heap_size(heap) == heap->capacity){
    heap_elem_t *tmp = realloc(heap->elems, heap->capacity * 2 * sizeof(heap_t));
    heap->capacity *= 2;
    heap->elems = tmp;
  }
  heap->elems[heap->size++] = new;
  heap_shift_up(heap, heap->size-1);
}

heap_elem_t heap_pop(heap_t *heap){
  heap_elem_t top = heap->elems[0];
  heap->elems[0] = heap->elems[--heap->size];
  heap_shift_down(heap, 0);
  return top;
}


int main() {
  heap_t *heap = heap_create(10, cmp_int);
  heap_push(heap, 10);
  heap_push(heap, 45);
  heap_push(heap, 3);
  heap_push(heap, 23);
  heap_push(heap, 5);
  heap_push(heap, 24);
  heap_push(heap, 1);
  heap_push(heap, 100);
  heap_push(heap, 76);
  while(!heap_empty(heap)){
    printf("%d ", heap_pop(heap));
  }
  printf("\n");
}
