#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

struct Queue {
    Node *front, *rear;
    Queue() {
        front, rear = nullptr;
    }

    void enqueue(int d) {
        Node* newNode = new Node(d);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;

        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr)
            return;

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void print(Node* node) {
        while (node != nullptr) {
            cout << node->data << "->";
            node = node->next;
        }

        cout << "NULL" << endl;
    }
};

void demo(Queue q) {
    q.print(q.front);

    cout << "Queue Front: " << q.front->data << endl;
    cout << "Queue Rear: " << q.rear->data << endl;
}

int main() {
    Queue q;

    q.enqueue(10);
    demo(q);

    q.enqueue(20);
    demo(q);

    q.dequeue();
    demo(q);

    q.enqueue(30);
    demo(q);

    q.enqueue(40);
    demo(q);

    q.enqueue(50);
    demo(q);

    q.dequeue();
    demo(q);

}