#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void printPostOrder(struct Node* node) {
    if (node == nullptr)
        return;

    printPostOrder(node->left);

    printPostOrder(node->right);

    cout << node->data << " ";
}

void printPreOrder(struct Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";

    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(struct Node* node) {
    if (node == nullptr)
        return;

    printInOrder(node->left);

    cout << node->data << " ";

    printInOrder(node->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printPostOrder(root);
    cout << endl;
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
}