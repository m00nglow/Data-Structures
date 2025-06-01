#include <iostream>

using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
    public:
        Node();

        Node(int);

        Node* minValueNode(Node* root);

        Node* insert(Node*, int);

        Node* deleteNode(Node*, int);

        void inOrder(Node*);
};

Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

Node* Node::insert(Node* root, int value) {
    if (!root) { //True when "root" is null
        return new Node(value);
    }

    if (value > root->data)
        root->right = insert(root->right, value);
    else
        root->left = insert(root->left, value);

    return root;
}

void Node::inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->insert(root, 20);
    root->insert(root, 30);
    root->insert(root, 5);
    root->insert(root, 6);

    root->inOrder(root);
}