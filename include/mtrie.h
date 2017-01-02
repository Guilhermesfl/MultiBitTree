#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node bnode;
typedef struct B_tree btree;
typedef struct Mbit_node mnode;
typedef struct Mbit_leaf mleaf;
typedef struct Node_entry n_entry;
typedef struct Leaf_entry l_entry;

struct Node{
	uint8_t key;
	int color;
	int type; //0 -> MULTIBITLEAF, 1 -> MULTIBITNODE
	int depth;
	bnode *left;
	bnode *right;
};

struct B_tree{
	bnode *root;
};

struct Mbit_node{
	n_entry *entrys;
};

struct Mbit_leaf{
	uint8_t *next_hop;
};

struct Node_entry{
	uint8_t next_hop;
	uint8_t depth;
	mleaf *l_branch;
	mnode *n_brach;
};

int ctoi(char c);
void printTree(bnode* node);
bnode* prefix_btree(void);
bnode* insert(bnode* node,int pfx[],int size, int *pos);
bnode* NewNode(void);
bnode* DFS(bnode* node,int a,int b);
bnode* DFS_visit(bnode* node,int a, int b);
bnode* constructor(bnode* node, int a, int b);