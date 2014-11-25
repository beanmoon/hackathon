#include <stdlib.h>
#include <string.h>


/**
 * @author beanmoon
 */

/* typedef int stack_elem_t; */
typedef void * stack_elem_t;


typedef struct{
  int size;
  int capacity;
  stack_elem_t *elems;
} stack_type;

stack_type * stack_create(int capacity){
  stack_type *s = (stack_type *)malloc(sizeof(stack_type));
  s->size = 0;
  s->capacity = capacity;
  s->elems = (stack_elem_t*)malloc(capacity * sizeof(stack_elem_t));
  return s;
}

void stack_destroy(stack_type *s){
  free(s->elems);
  free(s);
}

int stack_empty(const stack_type *s){
  return s->size == 0;
}

int stack_size(const stack_type *s){
  return s->size;
}

void stack_push(stack_type *s, stack_elem_t new){
  if(s->size == s->capacity){
    stack_elem_t *tmp = (stack_elem_t *)\
      realloc(s->elems, s->capacity * 2 * sizeof(stack_elem_t));
    s->elems = tmp;
    s->capacity = s->capacity * 2;
  }
  s->elems[s->size++] = new;
}

stack_elem_t stack_pop(stack_type *s){
  /* return s->elems[s->size--]; */
  return s->elems[--s->size];
}

/* int main(){ */
/*    return 0; */
/* } */
