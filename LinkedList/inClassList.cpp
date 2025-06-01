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
    cout << endl;
}

Node* delList(Node* head, int item) {
    Node* temp;
    if (head == nullptr)
        return head;
    if (head->data == item) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* t = head;
    while (t->next != nullptr && t->next->data != item)
        t = t->next;
    if (t->next == nullptr)
        return head;
    temp = t->next;
    t->next = t->next->next;
    free(temp);
    return head;
}

int main() {
    Node* head = nullptr;
    insertBeg(&head, 1);
    insertBeg(&head, 2);
    insertBeg(&head, 3);
    printList(head);
    head = delList(head, 3);
    printList(head);
    return 0;
}