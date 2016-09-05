#include <stdio.h>
#include <stdlib.h>
using namespace std;

class BtreeNode{
public:
	int t;
	int n;
	int *keys;
	BtreeNode** child;
	bool leaf;
	BtreeNode(int, bool);
	~BtreeNode();
	void insert_into_nonfull(int);
	void split_child(int, BtreeNode*);

friend class Btree;
};

class Btree{
public:
	BtreeNode* root;
	int t;
	Btree(int);
	~Btree();
	void insert(int);
};