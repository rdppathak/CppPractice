#include "Heap.h"

MinHeap::MinHeap(int capacity)
{
    heap_size = 0;
    this->capacity = capacity;
    harr = new int[capacity];
}

void MinHeap::insert_key(int key)
{
    if (heap_size == capacity)
    {
        cout <<"\n Overflow: could not insert key";
        return;
    }

    heap_size++;
    int i = heap_size -1;
    harr[i] = key;

    while(i != 0 && (harr[parent(i)] > harr[i]))
    {
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}

void MinHeap::print_heap()
{
    cout << "\nHeap Elements: ";
    for (int i=0; i<heap_size; i++){
        cout <<" "<<harr[i];
    }
    cout <<"\n";
}

void MinHeap::min_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        min_heapify(smallest);
    }
}

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
