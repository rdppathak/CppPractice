#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)

struct TrieNode{
    struct TrieNode alphabets[ALPHABET_SIZE];
    bool leaf_node;
};
