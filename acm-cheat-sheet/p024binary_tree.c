#include <stdio.h>
#include <stdlib.h>

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

  }
  visit(root);
  pre_order_r(root->left, visit);
  pre_order_r(root->right, visit);
}

void in_order_r(const tree_node_t *root,  int (*visit)(const tree_node_t*)){
  if(root == NULL){

  }
  in_order_r(root->left, visit);
  visit(root);
  in_order_r(root->right, visit);
}

void post_order_r(const tree_node_t *root,  int (*visit)(const tree_node_t*)){
  if(root == NULL){

  }
  visit(root);
  post_order_r(root->left, visit);
  post_order_r(root->right, visit);
}

int main() {
  tree_node_t *root;
  init_btree(root);
  int (*func)(const tree_node_t* root);
  func = visit;
  pre_order_r(root, func);
}


void init_btree(tree_node_t *root){
  root->value = 'A';
  tree_node_t * p1 = (tree_node_t*)malloc(sizeof(tree_node_t));
  p1->value = '+';
  root->left = p1;
  tree_node_t * p2 = (tree_node_t*)malloc(sizeof(tree_node_t));
  p2->value = '*';
  p1->left = p2;
  tree_node_t * p3 = (tree_node_t*)malloc(sizeof(tree_node_t));
  p3->value = '/';
  p2->left = p3;
  tree_node_t * p4 = (tree_node_t*)malloc(sizeof(tree_node_t));
  p4->value = 'O'; p4->left = p4->right = NULL;
  p3->left = p4;
  tree_node_t * q1 = (tree_node_t*)malloc(sizeof(tree_node_t));
  q1->value = 'G'; q1->left = q1->right = NULL;
  root->right = q1;
  tree_node_t * q2 = (tree_node_t*)malloc(sizeof(tree_node_t));
  q2->value = 'H'; q2->left = q2->right = NULL;
  p1->right = q2;
  tree_node_t * q3 = (tree_node_t*)malloc(sizeof(tree_node_t));
  q3->value = 'I'; q3->left = q3->right = NULL;
  p2->right = q3;
  tree_node_t * q4 = (tree_node_t*)malloc(sizeof(tree_node_t));
  q4->value = 'J'; q4->left = q4->right = NULL;
  p3->right = q4;
}
