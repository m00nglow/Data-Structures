#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void insertBeg(Node **headRef, int newData) {

    Node* newNode = new Node();

    newNode->data = newData;

    newNode->next = *headRef;

    *headRef = newNode;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << "" << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = nullptr;
    insertBeg(&head, 1);
    insertBeg(&head, 2);
    insertBeg(&head, 3);
    printList(head);
    return 0;
}