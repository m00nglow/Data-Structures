#include <iostream>

using namespace std;

#define MAX 100

class Stack {
    int top;

    public:
        int arr[MAX];

        Stack() {
            top = -1;
        }

        bool push(int item);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int item) {
    if(top >= (MAX - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    }

    else {
        top++;

        arr[top] = item;
        cout << item << endl;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    }

    else {
        int x = arr[top];
        top--;
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty" << endl;
    }

    else {
        int x = arr[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return top < 0;
}

void printStack(Stack s) {
    while (!s.isEmpty()) {
        cout << s.peek() << endl;
        s.pop();
    }
}

int main() {
    class Stack s;
    s.push(4);
    s.push(5);
    s.push(6);

    cout << "Elements present in stack: " << endl;
    printStack(s);

    cout << s.pop() << " is successfully popped from stack" << endl;

    cout << "Elements present in stack: " << endl;
    printStack(s);
    return 0;
}
