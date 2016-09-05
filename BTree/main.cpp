#include "Btree.h"

int main(){
	printf("Executing main function\n");
	Btree* tree = new Btree(2);
	tree->insert(10);
	tree->insert(20);
	tree->insert(30);
	tree->insert(40);
	tree->insert(20);
	printf ("Root Node keys %d %d %d\n",tree->root->keys[0],tree->root->keys[1],tree->root->keys[2]);
	printf ("Child node keys %d\n", tree->root->child[1]->keys[0]);
	return 0;
}