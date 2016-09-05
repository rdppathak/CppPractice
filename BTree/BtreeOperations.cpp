#include "Btree.h"

BtreeNode::BtreeNode(int t, bool leaf){
	this->t = t;
	this->leaf = leaf;
	// keys = (int*)malloc((2*t-1)*sizeof(int));
	// child = (BtreeNode*)malloc((t-1)*sizeof(BtreeNode));
	keys = new int[(2*t-1)];
	child = new BtreeNode *[2*t];
	n=0;
}

BtreeNode::~BtreeNode(){

}

void BtreeNode::insert_into_nonfull(int key){
	int index = n-1;
	if(leaf == true){
		while(index>=0 && keys[index] > key){
			keys[index+1] = keys[index];
			index--;
		}
		keys[index+1] = key;
		n++;
	}else{
		while((index>=0) && keys[index]>key)
			index--;

		if (child[index+1]->n == (2*t-1)){
			split_child(index+1, child[index+1]);
			if (keys[index+1] < key)
				index++;
		}
		child[index+1]->insert_into_nonfull(key);
	}
}

void BtreeNode::split_child(int i, BtreeNode* node){
	BtreeNode* new_node = new BtreeNode(node->t, node->leaf);
	new_node->n = t-1;
	for(int j=0;j<=t-1;j++){
		new_node->keys[j] = node->keys[j+t];
	}

	if (node->leaf){
		for(int j=0;j<t;j++){
			new_node->child[j] = node->child[j+t];
		}
	}

	node->n = t-1;

	for(int j=n; j>=i+1; j++){
		child[j+1] = child[j];
	}

	child[i+1] = new_node;

	for(int j=n-1; j>=i;j++){
		keys[j+1] = keys[j];
	}

	keys[i] = node->keys[t-1];

	n=n+1;
}

Btree::Btree(int t){
	this->t = t;
	root = NULL;
}

Btree::~Btree(){

}

void Btree::insert(int key){
	if (root == NULL){
		root = new BtreeNode(t, true);
		root->keys[0] = key;
		root->n = 1;
 	}else{
 		if (root->n == (2*t-1)){
 			BtreeNode* new_root;
 			new_root = new BtreeNode(t, false);
 			new_root->child[0] = root;

 			new_root->split_child(0, root);

 			int i = 0;
            if (new_root->keys[0] < key)
                i++;
            new_root->child[i]->insert_into_nonfull(key);
 			root = new_root;	

 		}else{
 			root->insert_into_nonfull(key);
 		}
 	}
}