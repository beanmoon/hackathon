#include <stdio.h>

typedef int tree_node_elem_t;

int visit(const tree_node_t *node){
  printf("%d ", node->value);
}
typedef struct tree_node_t{
  struct tree_node_t *left;
  struct tree_node_t *right;
  tree_node_elem_t value;
}tree_node_t;


int visit(const tree_node_t *node){
  printf("%d ", node->value);
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

}


void init_btree(node *root)

{

  root->data = 'A';

  node * p1 = (node*)malloc(sizeof(node));

  p1->data = '+';

  root->lchild = p1;

  node * p2 = (node*)malloc(sizeof(node));

  p2->data = '*';

  p1->lchild = p2;

  node * p3 = (node*)malloc(sizeof(node));

  p3->data = '/';

  p2->lchild = p3;

  node * p4 = (node*)malloc(sizeof(node));

  p4->data = 'O'; p4->lchild = p4->rchild = NULL;

  p3->lchild = p4;

  node * q1 = (node*)malloc(sizeof(node));

  q1->data = 'G'; q1->lchild = q1->rchild = NULL;

  root->rchild = q1;

  node * q2 = (node*)malloc(sizeof(node));

  q2->data = 'H'; q2->lchild = q2->rchild = NULL;

  p1->rchild = q2;

  node * q3 = (node*)malloc(sizeof(node));

  q3->data = 'I'; q3->lchild = q3->rchild = NULL;

  p2->rchild = q3;

  node * q4 = (node*)malloc(sizeof(node));

  q4->data = 'J'; q4->lchild = q4->rchild = NULL;

  p3->rchild = q4;

}
