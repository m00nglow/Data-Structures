#include <iostream>

using namespace std;

void printReverse(char str[], int n) {
    if (n == 0)
        return;
    cout << str[n - 1];
    printReverse(str, n - 1);
}

int pow(int x, int y) {
    if (y == 0)
        return 1;
    return x * pow(x, y - 1);
}

int nToN(int n) {
    if (n == 0)
        return 0;
    return pow(n, n) + nToN(n - 1);
}

int main() {
    printReverse("florida", 7);
    cout << endl;
    cout << nToN(2) << endl;
}