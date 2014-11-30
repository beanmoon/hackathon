#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "binary_tree_char.h"


void build_post(const char *pre, const char *in, int len, char *post){
  if(len <= 0) return;
  int left_len = strchr(in, pre[0]) - in;
  build_post(pre+1, in, left_len, post);
  build_post(pre+left_len+1, in+left_len+1, len-left_len-1, post+left_len);
  post[len-1] = pre[0];
}

#define MAX 64
void build_test(){
  char pre[MAX] = {0};
  char in[MAX] = {0};
  char post[MAX] = {0};
  scanf("%s %s", pre, in);
  int len = strlen(pre);
  build_post(pre, in, len, post);
  printf("string in post order: %s\n", post);
}



void rebuild(const char *pre,  const char *in, int len, tree_node_t **post){
  if(len <= 0 || pre == NULL || in == NULL)
    return;
  int left_len = strchr(in, pre[0]) - in;
  *post = malloc(sizeof(tree_node_t));
  (*post)->value = pre[0];
  (*post)->left = (*post)->right = NULL;

  rebuild(pre+1, in, left_len, &((*post)->left));
  rebuild(pre+left_len+1, in+left_len+1, len-left_len-1, &((*post)->right));
}

void print_post_order(tree_node_t *root){
  if(root == NULL)
    return;
  print_post_order(root->left);
  print_post_order(root->right);
  printf("%c ", root->value);
}

int main() {
  /* build_test(); */
  char *pre = "DBACEGF";
  char *in = "ABCDEFG";
  tree_node_t *post;
  rebuild(pre, in, strlen(pre), &post);
  print_post_order(post);
  printf("\n");
}
