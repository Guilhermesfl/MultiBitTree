#include "mtrie.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

node* NewNode(void) {
 
  node* x = (node*)malloc(sizeof(node));
  x->left = NULL; 
  x->right = NULL;

  return x; 
} 

node* insert(node* node,int pfx[],int size, int *pos) {

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

node* prefix_btree(void)
{
	char c;
	int pos = -1;
	int a1[] = {0,0,0,0,1,1};
	int a2[] = {0,0,0,0,1,0};

	node *root = NewNode();
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

void printTree(node* node) { 
  if (node == NULL) return;
  printf("%d ", node->key);
  printTree(node->left);  
  printTree(node->right); 
}
int ctoi(char c) {
    return c-'0';
}
