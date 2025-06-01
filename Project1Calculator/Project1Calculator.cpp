#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool areParenthesesBalanced(const string& s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty())
                return false;
            if (!isMatchingPair(st.top(), ch))
                return false;
            st.pop();
        }
    }

    return st.empty();
}

bool isValidInfix(const string& s) {
    if (s.empty()) {
        cout << "Invalid expression: String is empty." << endl;
    }

    if (!areParenthesesBalanced(s)) {
        cout << "Invalid expression: Parenthesis count is imbalanced." << endl;
        return false;
    }

    int operandCount = 0;
    int operatorCount = 0;
    string validChars = "+-*/%^()[]{} ";

    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]) && validChars.find(s[i]) == string::npos){
            cout << "Invalid expression: The character " << s[i] << " is invalid." << endl;
            return false;
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            while (i < s.length() && isdigit(s[i]))
                i++;
            operandCount++;
            i--;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
             s[i] == '/' || s[i] == '%' || s[i] == '^')
            operatorCount++;
    }

    if (operatorCount == 0 || operandCount == 0) {
        cout << "Invalid expression: Operator and/or operand count are zero" << endl;
        return false;
    }

    if (operatorCount >= operandCount) {
        cout << "Invalid expression: The operator count equals or exceeds the operand count." << endl;
        return false;
    }

    return true;
}

int getPrio(char ch) {
    if (ch == '+' || ch == '-') return 0;
    if (ch == '*' || ch == '/' || ch == '%') return 1;
    if (ch == '^') return 2;
    return -1;
}

string infixToPostfix(const string& infix) {
    string pstr;
    stack<char> st;
    string operators = "-+/%*^";
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isspace(ch)) //Skips if space
            continue;
        if (isdigit(ch)) {
            int j = i;
            while (j < infix.length() && isdigit(infix[j])) {
                pstr += infix[j];
                j++;
            }
            pstr += ' ';
            i = j - 1;  // Move main loop index to end of number
        }
        else if (operators.find(ch) != string::npos) { //If its an operator
            if (st.empty()) //If the stack is empty, just push it
                st.push(ch);
            else {
                if (getPrio(ch) > getPrio(st.top())) //If the prio is higher, just push it
                    st.push(ch);
                else {
                    while (!st.empty() && operators.find(st.top()) != string::npos && getPrio(ch) <= getPrio(st.top())) {
                        pstr += st.top();
                        pstr += ' ';
                        st.pop();
       }
                    st.push(ch);
                }
            }
        }
        else if (ch == '(' || ch == '[' || ch == '{') //If we encounter a parenthesis, add to stack
            st.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}') { //If we encounter a closing parenthesis, pop everything until the opening parenthesis
            while (!st.empty() && st.top() != '(' && st.top() != '[' && st.top() != '{') {
                pstr += st.top();
                pstr += ' ';
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
    }
    while (!st.empty()) {
        pstr += st.top();
        pstr += ' ';
        st.pop();
    }

    return pstr;
}

double evaluatePostfix(const string& postfix) {
    stack<double> st;
    string operators = "-+/%*^";

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            string numString;
            while (i < postfix.length() && isdigit(postfix[i])) {
                numString += postfix[i];
                i++;
            }
            i--;
            st.push(stod(numString));
        }
        if (operators.find(postfix[i]) != string::npos) {
            double eval = 0.0;
            // For a - b the stack would be b a, so you have to do b then a
            double second = st.top(); st.pop();  // second operand
            double first = st.top(); st.pop();  // first operand
            if (postfix[i] == '+')
                eval = first + second;
            else if (postfix[i] == '-')
                eval = first - second;
            else if (postfix[i] == '*')
                eval = first * second;
            else if (postfix[i] == '/')
                eval = first / second;
            else if (postfix[i] == '%')
                eval = fmod(first, second);
            else if (postfix[i] == '^')
                eval = pow(first, second);

            st.push(eval);
        }
    }

    return st.top();
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    if (!isValidInfix(infixExpression)) {
        cout << "Expression is invalid. Cannot convert or evaluate.\n";
        return 1;
    }

    string postfixExp = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExp << endl;

    double result = evaluatePostfix(postfixExp);
    cout << "Result: " << fixed << setprecision(3) << result << endl;

    return 0;
}