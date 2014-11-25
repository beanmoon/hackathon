#include <stdio.h>
#include <stdlib.h>
#include "p014stack.c"


typedef int tree_node_elem_t;

typedef struct tree_node_t{
  struct tree_node_t *left;
  struct tree_node_t *right;
  tree_node_elem_t value;
}tree_node_t;



void init_btree(tree_node_t *root);

int visit(const tree_node_t *node){
  printf("%d ", node->value);
  return 0;
}

void pre_order_r(const tree_node_t *root,  int (*visit)(const tree_node_t*)){
  if(root == NULL){
    return;
  }
  visit(root);
  pre_order_r(root->left, visit);
  pre_order_r(root->right, visit);
}

void in_order_r(const tree_node_t *root,  int (*visit)(const tree_node_t*)){
  if(root == NULL){
    return;
  }
  in_order_r(root->left, visit);
  visit(root);
  in_order_r(root->right, visit);
}

void post_order_r(const tree_node_t *root,  int (*visit)(const tree_node_t*)){
  if(root == NULL){
    return;
  }
  post_order_r(root->left, visit);
  post_order_r(root->right, visit);
  visit(root);
}

/**
 * @brief 先序遍历,非递归. */
void pre_order(const tree_node_t *root,
	       int (*visit)(const tree_node_t*)) {
  const tree_node_t *p;
  /* stack<const tree_node_t *> s; */
  stack_type *s = stack_create(20);

  p = root;
  if(p != NULL) stack_push(s,p);
  while(!stack_empty(s)) {
    p = stack_pop(s);
    visit(p);
    if(p->right != NULL) stack_push(s,p->right);
    if(p->left != NULL) stack_push(s,p->left);
  }
}

void in_order(const tree_node_t *root, int (*visit)(const tree_node_t*)){
  const tree_node_t *p;
  stack_type *s = stack_create(20);
  
  p = root;
  while(!stack_empty(s) || p != NULL){
    if(p != NULL){
      stack_push(s, p);
      p = p->left;
    } else {
      p = stack_pop(s);
      visit(p);
      p = p->right;
    }
  }    
}

void post_order(const tree_node_t *root, int (*visit)(const tree_node_t*)){
  const tree_node_t *p, *q;
  stack_type *s = stack_create(20);
  
  p = root;
  do{
    while(p != NULL){
      stack_push(s, p);
      p = p->left;
    }
    q = NULL;
    while(!stack_empty(s)){
      p = stack_pop(s);
      if(p->right == q){
	visit(p);
	q = p;
      }else{
	stack_push(s, p);
	p = p->right;
	break;
      }
    }
  }while(!stack_empty(s));
}

int main() {
  tree_node_t *root = malloc(sizeof(tree_node_t));
  init_btree(root);
  post_order(root, visit);
  printf("\n");
}


void init_btree(tree_node_t *root){
  root->left = root->right = NULL;
  root->value = 1;
  tree_node_t * p1 = malloc(sizeof(tree_node_t));
  /* p1->left默认值为1，这里一定要显式的声明为null，使其值为0，
   * 否则会报segmentation fault   */
  p1->left = NULL;  
  p1->right = NULL;
  p1->value = 2;
  root->left = p1;
  tree_node_t * p2 = malloc(sizeof(tree_node_t));
  p2->left = NULL; 
  p2->right = NULL;
  p2->value = 3;
  root->right = p2;
  tree_node_t * p3 = malloc(sizeof(tree_node_t));
  p3->value = 4;
  p3->left = p3->right = NULL;
  p1->left = p3;
  tree_node_t * p4 = malloc(sizeof(tree_node_t));
  p4->value = 5; 
  p4->left = p4->right = NULL;
  p1->right = p4;
  tree_node_t * p5 = malloc(sizeof(tree_node_t));
  p5->value = 6; p5->left = p5->right = NULL;
  p2->left = p5;
  tree_node_t * p6 = malloc(sizeof(tree_node_t));
  p6->value = 7; p6->left = p6->right = NULL;
  p2->right = p6;
  tree_node_t * p7 = malloc(sizeof(tree_node_t));
  p7->value = 8; p7->left = p7->right = NULL;
  p3->left = p7;
  tree_node_t * p8 = malloc(sizeof(tree_node_t));
  p8->value = 9; p8->left = p8->right = NULL;
  p3->right = p8;
}
