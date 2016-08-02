#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode{
    struct TrieNode *alphabets[ALPHABET_SIZE];
    bool leaf_node;
};

struct TrieNode* create_node();
void insert(struct TrieNode*, const char*);
bool search(struct TrieNode *, const char*);
