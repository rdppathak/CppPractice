#include "Heap.h"

int main()
{
    MinHeap heap = MinHeap(5);
    heap.insert_key(10);
    heap.insert_key(20);
    heap.insert_key(8);
    heap.insert_key(15);
    heap.insert_key(1);
    heap.print_heap();

    heap.min_heapify(0);

    cout << "\nHeap after Minimum Heapify\n";
    heap.print_heap();
    return 0;
}
