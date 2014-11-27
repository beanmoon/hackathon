#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

typedef struct tbt_node_t{
  int ltag, rtag;
  struct tbt_node_t *left, *right;
  elem_t value;
} tbt_node_t;

void in_thread(tbt_node_t *root, tbt_node_t **pre);
void in_thread2(tbt_node_t *root, tbt_node_t *pre);
void init_tbtree(tbt_node_t *root);


int visit(tbt_node_t *node){
  printf("%d ", node->value);
  return 0;
}

void create_in_thread(tbt_node_t *root){
  tbt_node_t *pre = NULL;
  if(root != NULL){
    in_thread(root, &pre);
    /* in_thread2(root, pre); */
    pre->right = NULL;
    pre->rtag = 1;
  }
}


void in_thread(tbt_node_t *root, tbt_node_t **pre){
  if(root != NULL){
    in_thread(root->left, pre);
    if(root->left == NULL){
      root->left = *pre;
      root->ltag = 1;
    }
    if(*pre != NULL && (*pre)->right == NULL){
      (*pre)->right = root;
      (*pre)->rtag = 1;
    }
    *pre = root;
    in_thread(root->right, pre);
  }
}

/**
 * we need to pass the address of the pointer of type 'tbt_node_t *', 
 * not the value of it
*/
void in_thread2(tbt_node_t *root, tbt_node_t *pre){
  if(root != NULL){
    in_thread2(root->left, pre);
    if(root->left == NULL){
      root->left = pre;
      root->ltag = 1;
    }
    if(pre != NULL && pre->right == NULL){
      pre->right = root;
      pre->rtag = 1;
    }
    pre = root;
    in_thread2(root->right, pre);
  }
}

tbt_node_t *first(tbt_node_t *root){
  if(root == NULL){
    return NULL;
  }
  tbt_node_t *ret = root;
  while(ret != NULL && ret->ltag != 1){
    ret = ret->left;
  }
  return ret;
}

tbt_node_t *next(tbt_node_t *root){
  if(root->rtag == 1)
    return root->right;
  else
    return first(root->right);
}

void traverse_in_order(tbt_node_t *root, int (*visit)(tbt_node_t *)){
  tbt_node_t *p = first(root);
  while(p != NULL){
    visit(p);
    p = next(p);
  }
  printf("\n");
}


int main() {
  tbt_node_t *root = malloc(sizeof(tbt_node_t));
  init_tbtree(root);
  create_in_thread(root);
  traverse_in_order(root, visit);
}


void init_tbtree(tbt_node_t *root){  
  root->left = root->right = NULL;
  root->value = 1;
  tbt_node_t * p1 = malloc(sizeof(tbt_node_t));
  /* p1->left默认值为1，这里一定要显式的声明为null，使其值为0，
   * 否则会报segmentation fault   */
  p1->left = NULL;  
  p1->right = NULL;
  p1->value = 2;
  root->left = p1;
  tbt_node_t * p2 = malloc(sizeof(tbt_node_t));
  p2->left = NULL; 
  p2->right = NULL;
  p2->value = 3;
  root->right = p2;
  tbt_node_t * p3 = malloc(sizeof(tbt_node_t));
  p3->value = 4;
  p3->left = p3->right = NULL;
  p1->left = p3;
  tbt_node_t * p4 = malloc(sizeof(tbt_node_t));
  p4->value = 5; 
  p4->left = p4->right = NULL;
  p1->right = p4;
  tbt_node_t * p5 = malloc(sizeof(tbt_node_t));
  p5->value = 6; p5->left = p5->right = NULL;
  p2->left = p5;
  tbt_node_t * p6 = malloc(sizeof(tbt_node_t));
  p6->value = 7; p6->left = p6->right = NULL;
  p2->right = p6;
  tbt_node_t * p7 = malloc(sizeof(tbt_node_t));
  p7->value = 8; p7->left = p7->right = NULL;
  p3->left = p7;
  tbt_node_t * p8 = malloc(sizeof(tbt_node_t));
  p8->value = 9; p8->left = p8->right = NULL;
  p3->right = p8;
}
