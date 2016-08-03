#include "BIT.h"


int* construct_bit_tree(int arr[], int size){
    int* bit_tree = new int[size+1];

    for (int i=0;i<size+1;i++){
        bit_tree[i] = 0;
    }

    for (int i=0;i<size;i++){
        update_bit_tree(bit_tree, size, i, arr[i]);
    }
    return bit_tree;
}

void update_bit_tree(int bit_tree[], int size, int i, int value){
    int index = i +1;

    while(index<=size){
        bit_tree[index] += value;
        index += (index &(-index));
    }
}

int get_sum(int bit_tree[], int index){
    index = index+1;
    int sum=0;
    while(index>0){
        sum += bit_tree[index];
        index -=(index&(-index));
    }
    return sum;
}
