#include <iostream>
#include <ranges>

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

    int i = heapSize;
    harr[i] = key;
    heapSize++;

    percolateUp(i);
}

MinHeap* initHeapfromArray(int *values, int length) {
    MinHeap *heap = new MinHeap(length);

    for (int i = 0; i < length; i++) {
        heap->insertKey(values[i]);  // insert into the NEW heap, not this one
    }

    return heap;
}


int MinHeap::minimum(int a, int indexa, int b, int indexb) {
    if (a < b)
        return indexa;
    else
        return indexb;
}

void MinHeap::percolateUp(int index) {
    while (index > 0 && harr[(index - 1) / 2] > harr[index]) {
        swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void MinHeap::percolateDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heapSize && harr[left] < harr[smallest])
        smallest = left;
    if (right < heapSize && harr[right] < harr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(index, smallest);
        percolateDown(smallest);
    }
}


int MinHeap::extractMin() {
    if (heapSize <= 0)
        return -1;

    int root = harr[0];
    harr[0] = harr[heapSize - 1];
    heapSize--;
    percolateDown(0);

    return root;
}


void MinHeap::heapify() {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        percolateDown(i);
    }
}


void MinHeap::swap(int index1, int index2) {
    int temp = harr[index1];
    harr[index1] = harr[index2];
    harr[index2] = temp;
}

void sort(int values[], int length) {
    MinHeap* heap = new MinHeap(length);

    heap = initHeapfromArray(values, length);

    for (int i = 0; i < length; i++) {
        values[i] = heap->extractMin();
        cout << "array[" << i << "]:" << values[i] << endl;
    }
}

int main() {
    int vals[6] = {14, 423, 52, 534, 13, 9};
    sort(vals, size(vals));
    MinHeap* heap = initHeapfromArray(vals, size(vals));
}