#include "TrieNode.h"

struct TrieNode* create_node(){
    struct TrieNode* node = NULL;
    node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (node){
        node->leaf_node = false;

        for(int i=0;i<ALPHABET_SIZE;i++)
            node->alphabets[i] = NULL;
    }

    return node;
}
