#include <iostream>

using namespace std;

class MinHeap {
    int *harr;
    int capacity;
    int heapSize;
    public:
    MinHeap(int capacity);
    void heapify();
    int extractMin();
    void insertKey(int key);
    void percolateUp(int index);
    void percolateDown(int index);
    int minimum(int a, int indexa, int b, int indexb);
    void swap(int index1, int index2);
    MinHeap *initHeapfromArray(int *values, int length);
};

MinHeap::MinHeap(int cap) {
    heapSize = 0;
    capacity = cap;
    harr = new int[capacity];
}

void MinHeap::insertKey(int key) {
    if (heapSize == capacity) {
        cout << "Overflow: Could not insert key" << endl;
        return;
    }

    heapSize++;
    int i = heapSize;
    harr[i] = key;

    percolateUp(i);
}

MinHeap* MinHeap::initHeapfromArray(int *values, int length) {
    MinHeap *heap = new MinHeap(length);

    for (int i = 1; i < length; i++) {
        insertKey(values[i]);
    }

    heap->heapSize = length;

    heap->heapify();

    return heap;
}

int MinHeap::minimum(int a, int indexa, int b, int indexb) {
    if (a < b)
        return indexa;
    else
        return indexb;
}

void MinHeap::percolateUp(int index) {
    if (index > 1) {
        if (harr[index / 2] > harr[index]) {
            swap(index, index/2);
            percolateUp(index/2);
        }
    }
}

void MinHeap::percolateDown(int index) {
    int min;

    if ((2 * index + 1) <= heapSize) {
        min = minimum(harr[2 * index], 2 * index, harr[2 * index + 1], 2 * index + 1);

        if (harr[index] > harr[min])
            swap(index, min);

        percolateDown(min);
    }
    else if (heapSize == 2*index) {
        if (harr[index] > harr[2*index])
            swap(index, 2*index);
    }
}

int MinHeap::extractMin() {
    int retval;

    if (heapSize > 0) {

    }
}