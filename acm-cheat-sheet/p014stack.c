#include <stdlib.h>
#include <string.h>

typedef int stack_elem_t;

typedef struct stack_t{
  int size;
  int capacity;
  stack_elem_t *elems;
} stack_t;

stack_t * stack_create(int capacity){
  stack_t *s = (stack_t *)malloc(sizeof(stack_t));
  s->size = 0;
  s->capacity = capacity;
  s->elems = (stack_elem_t*)malloc(capacity * sizeof(stack_elem_t));
  return s;
}

void stack_destroy(stack_t *s){
  free(s->elems);
  free(s);
}

int stack_empty(const stack_t *s){
  return s->size == 0;
}

int stack_size(const stack_t *s){
  return s->size;
}

void stack_push(stack_t *s, stack_elem_t new){
  if(s->size == s->capacity){
    stack_elem_t *tmp = (stack_elem_t *)\
      realloc(s->capacity * 2 * sizeof(stack_elem_t));
    s->elems = tmp;
    s->capacity = s->capacity * 2;
  }
  s->elems[size++] = new;
}

stack_elem_t stack_pop(const stack_t *s){
  return s->[size--];
}
