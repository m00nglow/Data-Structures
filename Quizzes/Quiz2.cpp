// Consider the following Queue class implementation. You want to keep the class simple and have only two methods (enqueue and dequeue). Assume that enqueue method is already implemented. Implement dequeue method.
#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value)
    {
        // already implemented
        if (rear == nullptr)
        {
            front = rear = new Node(value);
        }
        else
        {
            rear->next = new Node(value);
            rear = rear->next;
        }
    }

    void print()
    {
        Node *current = front;
        while (current != nullptr)
        {
            std::cout << current->data << ">>";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void dequeue() {
        if (front == nullptr)
            return;
        if (front == rear){
            front = rear = nullptr;
            return;
        }
        Node* temp = front->next;
        delete front;
        front = temp;

    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    q.dequeue();
    q.print();
};
