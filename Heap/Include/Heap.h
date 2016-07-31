#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

void swap(int* i, int* j);

class MinHeap{
    private:
        int *harr;
        int capacity;
        int heap_size;

    public:
        MinHeap(int capacity);
        int parent(int i){return ((i-1)/2);}
        int left(int i){return (2*i + 1);}
        int right(int i){return (2*i + 2);}
        void insert_key(int key);
        void print_heap();
        void min_heapify(int i);
};
