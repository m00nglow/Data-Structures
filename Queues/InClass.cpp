#include <iostream>

using namespace std;

class Queue {
    public:
        int front, rear, size;
        int capacity;
        int* array;
};

Queue* createQueue(int capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->size = 0;
    queue->front, queue->rear = -1;
    queue->array = new int[capacity];

    return queue;
}

int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        cout << "Error: queue is full, cannot enqueue." << endl;
        return;
    }
    queue->rear = (queue->rear + 1) % (queue->capacity);
    queue->array[queue->rear] = data;
    if (queue->front == -1)
        queue->front = queue->rear;

    queue->size++;
    cout << data << endl;
}

int main() {
    Queue* queue = createQueue(5);
    cout << isFull(queue) << endl;
    enqueue(queue, 10);
    return 0;
}
