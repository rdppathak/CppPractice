#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct MaxHeap
{
    int *arr;
    int size;
};

void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }

void print_array(int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        cout <<" "<<arr[i] ;
    }
    cout <<"\n";
}

void max_heapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;
    int left = (idx << 1) + 1;
    int right = (idx + 1) << 1;

    if (left < maxHeap->size && maxHeap->arr[left] < maxHeap->arr[largest])
        largest = left;

    if (right < maxHeap->size && maxHeap->arr[right] < maxHeap->arr[largest])
        largest = right;

    if (largest != idx)
    {
        printf("Swapping elements [%d] & [%d]\n", maxHeap->arr[largest], maxHeap->arr[idx]);
        swap(&maxHeap->arr[largest], &maxHeap->arr[idx]);
        max_heapify(maxHeap, largest);
    }
}

struct MaxHeap* createAndBuildHeap(int *arr, int size)
{
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;
    maxHeap->arr = arr;

    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        max_heapify(maxHeap, i);
    return maxHeap;
}
void heap_sort(int *arr, int size)
{
    struct MaxHeap* maxHeap = createAndBuildHeap(arr, size);
    printf("Element positions after heap build\n");
    print_array(arr, size);
    while (maxHeap->size > 1)
    {
        swap(&maxHeap->arr[0], &maxHeap->arr[maxHeap->size - 1]);
        --maxHeap->size;

        max_heapify(maxHeap, 0);
        printf("Element position after iteration: [%d]\n", maxHeap->size);
        print_array(maxHeap->arr, size);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout <<"Size of array: "<<size <<"\n";
    cout <<"List of array elements: ";
    print_array(arr, size);

    heap_sort(arr, size);
    cout <<"Sorted array: ";
    print_array(arr, size);

    return 0;
}
