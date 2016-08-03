#include "BIT.h"

int main(){
    int arr[] = {1,2,3,4,5,6};
    int *bit_tree;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Input array: \n");
    for (int i=0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Calculating BIT for array of size[%d]\n", size);
    bit_tree = construct_bit_tree(arr, size);
    printf ("Constructed BIT tree for given array is as follows: \n");
    for (int i=0;i<size+1;i++){
        printf("%d ", bit_tree[i]);
    }
    printf("\n");

    printf("Getting sum of [0..4] elements: %d\n", get_sum(bit_tree, 4));

    int index = 3;
    int new_value = 5;
    arr[index] += new_value;
    printf("Updated Input array: \n");
    for (int i=0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Updating element[%d] with value[%d]\n", index, new_value);
    update_bit_tree(bit_tree, size, index, new_value);

    printf("Getting sum of [0..4] elements after update: %d\n", get_sum(bit_tree, 4));

    return 0;
}
