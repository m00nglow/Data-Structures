#include <cmath>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

#define MAX 100

class Stack {
    public:
        int top;
        char exp[MAX];

        Stack() {
            top = -1;
        }

        bool push(char item);
        char pop();
};

bool Stack::push(char item) {
    if (top >= (MAX - 1)) {
        cout << "Stack overflow" << endl;
        return false;
    }

    else {
        top++;
        exp[top] = item;
        return true;
    }
}

char Stack::pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return 0;
    }

    else {
        char x = exp[top];
        top--;
        return x;
    }
}

int isMatchingPair(char c1, char c2) {
    if (c1 == '(' && c2 == ')')
        return 1;

    if (c1 == '[' && c2 == ']')
        return 1;

    if (c1 == '{' && c2 == '}')
        return 1;

    return 0;
}

int areParenthesisBalanced(char exp[]) {
    int i = 0;

    Stack* s = new Stack();

    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            s->push(exp[i]);

        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (s->top < 0)
                return 0;
            else if (!isMatchingPair(s->pop(), exp[i]))
                return 0;
        }
        i++;
    }
    if (s->top < 0)
        return 1;
    else
        return 0;
}

int main() {
    string input;
    cin >> input;
    char exp[MAX];
    for (int i = 0; i < MAX; i++) {
        exp[i] = input[i];
    }
    areParenthesisBalanced(exp) ? (cout << "Balanced\n") : (cout << "Not Balanced\n");
}