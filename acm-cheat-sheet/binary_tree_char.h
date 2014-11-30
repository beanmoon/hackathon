/* @(#)binary_tree.h
 */

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H 1

typedef char tree_elem_t;

typedef struct tree_node_t{
  struct tree_node_t *left;
  struct tree_node_t *right;
  tree_elem_t value;
}tree_node_t;

#endif /* _BINARY_TREE_H */

