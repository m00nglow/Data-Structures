#include "Stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack()
{
    front = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
void Stack<T>::push(const T &val)
{
    Node<T>* newNode = new Node<T>(val);
    if (front == nullptr) {
        newNode->next = nullptr;
        front = newNode;
        return;
    }
    newNode->next = front;
    front = newNode;
}

template <typename T>
void Stack<T>::pop()
{
    if (front == nullptr)
        return;
    Node<T>* temp = front;
    front = front->next;
    delete temp;
}
template <typename T>
const T &Stack<T>::top() const
{
    if (empty())
    {
        throw std::string("Empty stack");
    }
    else
    {
        // TODO: modify the line below
        return front->data;
    }
}
template <typename T>
bool Stack<T>::empty() const
{
    return (front == nullptr);
}

template <typename T>
void Stack<T>::print() const
{
    if (front == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node<T> *cur = front;
    std::cout << '[';
    while (cur->next != nullptr) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << cur->data;
    std::cout << "]\n";
}
