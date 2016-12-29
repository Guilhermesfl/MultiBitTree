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
	int a1[] = {0,0,0,0,1,1};
	int a2[] = {0,0,0,0,1,0};

	bnode *root = NewNode();
	root->key = 0.5;
	//FILE *pfxs = fopen("teste.txt", "rb");
	insert(root,a1,6,&pos);
	pos = -1;
	insert(root,a2,6,&pos);
	printf("\n");
  	printTree(root);

  	//fclose(pfxs);

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
int DFS(bnode* node)
{
	int depth = 0;

	if(node->left->color == 0 && node->left != NULL) node->left = DFS_visit(node->left,&depth);
	if(node->right->color == 0 && node->left != NULL)node->right = DFS_visit(node->right,&depth);

	return depth;
}
bnode* DFS_visit(bnode* node, int* depth)
{
	*depth = *depth + 1;
	node->color = 1;

	if(node->left->color == 0 && node->left != NULL) node->left = DFS_visit(node->left,depth);
	if(node->right->color == 0 && node->left != NULL) node->right = DFS_visit(node->right,depth);

	node->color = 0;

	return node;
}
bnode* constructor(bnode* node, int a, int b)
{
	if((DFS(node->left)== b) || (DFS(node->right)== b)) node->type = 0;
 	else{
		if((DFS(node)%a) == 0) node->type = 1;
		constructor(node->left,a,b);
		constructor(node->right,a,b);
		if((DFS(node->left)== b) || (DFS(node->right)== b)) node->type = 0;
	}
	return node;
}