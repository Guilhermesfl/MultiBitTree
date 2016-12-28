#include "mtrie.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

node* NewNode(uint8_t key) { 
  node* x = (node*)malloc(sizeof(node));    // "new" is like "malloc" 
  x->key = key; 
  x->left = NULL; 
  x->right = NULL;

  return x; 
} 

node* insert(node* node, uint8_t key) { 

	if (node == NULL) return NewNode(key); 
	else {
    if (key <= node->key) node->left = insert(node->left, key); 
		else node->right = insert(node->right, key);
    return node;
  } 
}

node* prefix_btree(void)
{
	//FILE *prefixes = fopen("prefixes.txt", "r");
	int a = 101;
	node *root = NewNode(0);
	insert(root,a);
  printTree(root);

  return root;
} 

void printTree(node* node) { 
  if (node == NULL) return;
  printTree(node->left); 
  printf("%d ", node->key); 
  printTree(node->right); 
} 