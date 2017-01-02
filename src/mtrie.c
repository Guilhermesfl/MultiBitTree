#include "mtrie.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int ctoi(char c) {
    return c-'0';
}

bnode* NewNode(void) {
 
  bnode* x = (bnode*)malloc(sizeof(bnode));
  x->left = NULL; 
  x->right = NULL;
  x->color = 0;

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
	printf("\n");
  	printTree(root);


 	return root;
} 

void printTree(bnode* node) { 
  if (node == NULL) return;
  printf("%d ", node->key);
  printTree(node->left);  
  printTree(node->right); 
}
/*********************************************
* DFS gives us the depth of the current node
**********************************************/
bnode* DFS(bnode* node,int a,int b)
{
	if(node->left->color == 0 && node->left != NULL) node->left = DFS_visit(node->left,a,b);
	if(node->right->color == 0 && node->right != NULL)node->right = DFS_visit(node->right,a,b);

	return node;
}
bnode* DFS_visit(bnode* node,int a, int b)
{
	node->color = 1;
	node = constructor(node,a,b);

	if(node->left->color == 0 && node->left != NULL) node->left = DFS_visit(node->left,a,b);
	if(node->right->color == 0 && node->right != NULL) node->right = DFS_visit(node->right,a,b);

	node->color = 2;

	return node;
}
bnode* constructor(bnode* node, int a, int b)
{
	if((node->left->depth==b && node->left != NULL) || (node->right->depth==b && node->right != NULL)) node->type = 0;
 	else{
		if((node->depth%a) == 0) node->type = 1;
		constructor(node->left,a,b);
		constructor(node->right,a,b);
		if((node->left->depth==b && node->left != NULL) || (node->right->depth==b && node->right != NULL)) node->type = 0;
	}
	return node;
}