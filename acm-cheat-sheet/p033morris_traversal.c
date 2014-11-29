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

int visit(tree_node_t *node){
  printf("%d ", node->value);
  return 0;
}


void morris_in_traversal(tree_node_t *root, int (*visit)(tree_node_t *node)){
  tree_node_t *pre, *cur;
  cur = root;
  while(cur != NULL){
    if(cur->left == NULL){
      visit(cur);
      cur = cur->right;
    } else {
      pre = cur->left;
      while(pre->right != NULL && pre->right != cur)
	pre = pre->right;
      if(pre->right == NULL){
	pre->right = cur;
	cur = cur->left;
      }else{
	visit(cur);
	pre->right = NULL;
	cur = cur->right;
      }
    }    
  }
}


void morris_pre_traversal(tree_node_t *root, int (*visit)(tree_node_t *node)){
  tree_node_t *pre, *cur;
  cur = root;
  while(cur != NULL){
    if(cur->left == NULL){
      visit(cur);
      cur = cur->right;
    } else {
      pre = cur->left;
      while(pre->right != NULL && pre->right != cur)
	pre = pre->right;
      if(pre->right == NULL){
	visit(cur);
	pre->right = cur;
	cur = cur->left;
      }else{
	pre->right = NULL;
	cur = cur->right;
      }
    }    
  }
}

void reverse_traversal_without_stack(tree_node_t *from, tree_node_t *to, 
		       int (*visit)(tree_node_t *node));
void reverse_traversal_with_stack(tree_node_t *from, tree_node_t *to, 
		       int (*visit)(tree_node_t *node));

void morris_post_traversal(tree_node_t *root, int (*visit)(tree_node_t *node)){
  tree_node_t dump = {root, NULL, 0};
  
  tree_node_t *pre, *cur;
  cur = &dump;
  while(cur != NULL){
    if(cur->left == NULL){
      cur = cur->right;
    } else {
      pre = cur->left;
      while(pre->right != NULL && pre->right != cur)
	pre = pre->right;
      if(pre->right == NULL){
	pre->right = cur;
	cur = cur->left;
      }else{
	reverse_traversal_without_stack(cur->left, pre, visit);
	pre->right = NULL;
	cur = cur->right;
      }
    }    
  }
}

void reverse(tree_node_t *from, tree_node_t *to){
  tree_node_t *x = from, *y = from->right, *z;
  while(x != to){
    z = y->right;
    y->right = x;
    x = y;
    y = z;
  }
}

void reverse_traversal_without_stack(tree_node_t *from, tree_node_t *to, 
				     int (*visit)(tree_node_t *node)){
  tree_node_t *p = to;
  reverse(from, to);
  while(1){
    visit(p);
    if(p == from)
      break;
    p = p->right;
  }
  reverse(to, from);
}


void reverse_traversal_with_stack(tree_node_t *from, tree_node_t *to, 
		       int (*visit)(tree_node_t *node)){
  stack_type *s = stack_create(10);
  tree_node_t *p = from;
  for(; p != to; p = p->right)
    stack_push(s, p);
  visit(p);
  while(!stack_empty(s)){
    p = stack_pop(s);
    visit(p);
  }
  /* printf("reverse_traversal executed\n"); */
}
int main() {
  tree_node_t *root = malloc(sizeof(tree_node_t));
  init_btree(root);
  morris_post_traversal(root, visit);
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
