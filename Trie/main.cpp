#include "TrieNode.h"

int main(){
    char keys[][256] = {"data", "druva"};

    struct TrieNode *root = create_node();

    for (int i=0;i<ARRAY_SIZE(keys); i++){
        printf("Adding string[%s] to tries\n", keys[i]);
        insert(root, keys[i]);
    }
    printf ("String status: %d\n",search(root, "solutions"));
    return 0;
}
