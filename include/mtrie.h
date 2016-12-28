#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct B_tree btree;

struct Node{
	uint8_t key;
	node *left;
	node *right;
};

struct B_tree{
	node *root;
};

void printTree(node* node);
node* prefix_btree(void);
node* insert(node* node, uint8_t key);
node* NewNode(uint8_t key);