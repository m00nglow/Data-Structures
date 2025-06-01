#ifndef STACK_H
#define STACK_H


template <typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void push(const T& val);
    void pop();
    const T& top() const;
    bool empty() const;
    void print() const;

private:
    template <typename T2>
    class Node {
        public:
            T2 data;
            Node<T2>* next;
            Node(const T2& val = T2(), Node<T2>* n = nullptr) : data(val), next(n) {};
    };
    Node<T>* front; 
};

#endif