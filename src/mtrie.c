#include "mtrie.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

bnode* NewNode(void) {
 
  bnode* x = (bnode*)malloc(sizeof(bnode));
  x->left = NULL; 
  x->right = NULL;
  x->color = 0;
  x->type = -1;

  return x; 
} 

bnode* insert(bnode* node,int pfx[],int size, int *pos) {

	if(*pos == size) return node;
	else{
		if (node == NULL){
			node = NewNode();
			node->depth = *pos+1; 
			node->key = pfx[*pos];
			*pos = *pos + 1; 
			if(pfx[*pos] <= 0) node->left = insert(node->left,pfx,size,pos);
			else node->right = insert(node->right,pfx,size,pos);
		} else {
			*pos = *pos + 1;
    		if (pfx[*pos] <= 0) node->left = insert(node->left,pfx,size,pos); 
    		else node->right = insert(node->right,pfx,size,pos);	
  		}
  	}
}

bnode* prefix_btree(void)
{
	char c;
	int pos = -1;
	int a1[] = {0,0,0,0,0};
	int a2[] = {0,0,0,0,1};
	int a3[] = {0,0,0,1};
	int a4[] = {0,0,1};
	int a5[] = {0,0,1,0,0,0,0};
	int a6[] = {0,0,1,0,0,0,1};
	int a7[] = {0,0,1,0,1};
	int a8[] = {0,0,1,1,1};
	int a9[] = {1,0};

	bnode *root = NewNode();
	root->key = 0.5;
	insert(root,a1,5,&pos);
	pos = -1;
	insert(root,a2,5,&pos);
	pos = -1;
	insert(root,a3,4,&pos);
	pos = -1;
	insert(root,a4,3,&pos);
	pos = -1;
	insert(root,a5,7,&pos);
	pos = -1;
	insert(root,a6,7,&pos);
	pos = -1;
	insert(root,a7,5,&pos);
	pos = -1;
	insert(root,a8,5,&pos);
	pos = -1;
	insert(root,a9,2,&pos);

 	return root;
} 

void printTree(bnode* node) { 
  if (node == NULL) return;
  printf("%d ", node->key);
  //printf("%d ", node->type);
  printTree(node->left);  
  printTree(node->right); 
}
/*********************************************
*Traverse the tree to construct the multibit
*nodes and leaves 
**********************************************/

bnode* DEPTH(bnode* node,int a,int b, int *node_depth, int *subtrie_depth)
{
	if(node->left != NULL){
		node->left = DEPTH_visit(node->left,a,b,node_depth,subtrie_depth);
		*node_depth = *node_depth - 1; 
	}
	if(node->right != NULL){
		node->right = DEPTH_visit(node->right,a,b,node_depth,subtrie_depth);
		*node_depth = *node_depth - 1;
	}
	return node;
}

bnode* DEPTH_visit(bnode* node,int a, int b, int *node_depth, int *subtrie_depth)
{
	*node_depth = *node_depth + 1;
	if(*node_depth > *subtrie_depth) *subtrie_depth = *subtrie_depth + 1;

	if(node->left != NULL){
		node->left = DEPTH_visit(node->left,a,b,node_depth,subtrie_depth);
		*node_depth = *node_depth - 1; 
	}
	if(node->right != NULL){
		node->right = DEPTH_visit(node->right,a,b,node_depth,subtrie_depth);
		*node_depth = *node_depth - 1; 
	}

	return node;
}

bnode* constructor(bnode* node, int a, int b)
{
	int node_depth = 0,subtrie_depth = -1;
	node = DEPTH(node,a,b,&node_depth,&subtrie_depth);
	printf("subtrie_depth = %d, node_depth =  %d\n", subtrie_depth, node_depth);
	if(subtrie_depth==b) node->type = 0;
 	else{
		if((node->depth%a) == 0) node->type = 1;
		if(node->left != NULL) constructor(node->left,a,b);
		if(node->right != NULL) constructor(node->right,a,b);
		if(subtrie_depth==b) node->type = 0;
	}
	return node;
}