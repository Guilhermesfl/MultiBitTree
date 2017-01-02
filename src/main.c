#include <stdio.h>
#include <stdlib.h>
#include "mtrie.h"
#include <inttypes.h>

int main(int argc, char const *argv[])
{
	int subtrie_depth = 0, node_depth = 0;
	bnode *x = prefix_btree();
	x = DFS(x,2,3,&node_depth,&subtrie_depth);

	return 0;
}