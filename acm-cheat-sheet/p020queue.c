#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @author beanmoon
 */

/* typedef int queue_item_t;*/
// define queue_item_t to void * to fit in p024binary_tree.c
typedef void * queue_item_t;

typedef struct queue_t{
  int front;
  int rear;
  int capacity;
  queue_item_t *elems;
} queue_t;


queue_t *queue_create(int capacity){
  queue_t *q = (queue_t*)malloc(sizeof(queue_t));
  q->front = 0;
  q->rear = 0;
  q->capacity = capacity;
  q->elems = (queue_item_t *)malloc(sizeof(queue_item_t) * capacity);
  return q;
}

void queue_destroy(queue_t *q){
  free(q->elems);
  free(q);
}

int queue_empty(queue_t *q){
  return q->front == q->rear;
}

int queue_size(queue_t *q){
  return (q->rear - q->front + q->capacity) % q->capacity;
}

void queue_push(queue_t *q, const queue_item_t item){
  if((q->rear+1) % q->capacity == q->front){
    queue_item_t *tmp = (queue_item_t*)malloc
      (q->capacity * 2 * sizeof(queue_item_t));
    if(q->front < q->rear){
      memcpy(tmp, q->elems+q->front, (q->rear - q->front) * sizeof(queue_item_t));
      q->rear -= q->front;
      q->front = 0;
    }else{
      memcpy(tmp, q->elems+q->front, (q->capacity - q->front) * sizeof(queue_item_t));
      memcpy(tmp + q->capacity - q->front, q->elems, q->rear * sizeof(queue_item_t));
      q->rear += q->capacity = q->front;
      q->front = 0;
    }
    free(q->elems);
    q->elems = tmp;
    q->capacity *= 2;
  }
  q->elems[q->rear] = item;
  q->rear = (q->rear + 1) % q->capacity;
}

queue_item_t queue_pop(queue_t *q){
  queue_item_t val = q->elems[q->front];
  q->front = (q->front + 1) % q->capacity;
  return val;
}

queue_item_t queue_front(queue_t *q){
  return q->elems[q->front];
}

queue_item_t queue_rear(queue_t *q){
  return q->elems[(q->rear-1 + q->capacity) % q->capacity];
}



