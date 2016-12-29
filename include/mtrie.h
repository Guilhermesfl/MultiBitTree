#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node bnode;
typedef struct B_tree btree;
typedef struct Mb_node mnode;
typedef struct Mb_leaf mleaf;

struct Node{
	uint8_t key;
	int color;
	int type; //0 -> MULTIBITLEAF, 1 -> MULTIBITNODE
	bnode *left;
	bnode *right;
};

struct B_tree{
	bnode *root;
};


int ctoi(char c);
void printTree(bnode* node);
bnode* prefix_btree(void);
bnode* insert(bnode* node,int pfx[],int size, int *pos);
bnode* NewNode(void);
int DFS(bnode* node);
bnode* DFS_visit(bnode* node, int* depth);
bnode* constructor(bnode* node, int a, int b);