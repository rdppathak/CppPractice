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

void insert(struct TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *next_node = root;
    for (level=0;level<length; level++){
        index = CHAR_TO_INDEX(key[level]);

        if (!next_node->alphabets[index]){
            next_node->alphabets[index] = create_node();
        }

        next_node = next_node->alphabets[index];
    }
    next_node->leaf_node = true;
}

bool search(struct TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *next_node = root;
    for(level=0;level<length;level++){
        index=CHAR_TO_INDEX(key[level]);
        if(!next_node->alphabets[index]){
            return false;
        }
        next_node = next_node->alphabets[index];
    }
    return ((next_node!=NULL) && next_node->leaf_node);
}
