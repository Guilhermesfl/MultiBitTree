#include <stdio.h>
#include <stdlib.h>
#include "mtrie.h"
#include <inttypes.h>

int main(int argc, char const *argv[])
{
	int subtrie_depth = 0, node_depth = 0, a,b;
	a = 2;
	b = 3;
	bnode *x = prefix_btree();
	x =  constructor(x,a,b);

  	printTree(x);
  	printf("\n");

	return 0;
}