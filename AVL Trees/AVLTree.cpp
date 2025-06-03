#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;

    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    x->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else //No equal keys
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int bal = getBalance(node);

    //Left Left Case
    if (bal > 1 && key < node->left->key)
        return rightRotate(node);

    //Right Right Case
    if (bal < -1 && key > node->right->key)
        return leftRotate(node);

    //Left Right Case
    if (bal > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //Right Left Case
    if (bal < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* node) {
    if (node == nullptr)
        return;

    cout << node->key << " ";

    preOrder(node->left);
    preOrder(node->right);
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* node, int key) {
    if (node == nullptr)
        return node;
    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else
                *node = *temp;
            free(temp);
        }
        else {
            Node* temp = minValueNode(node->right);

            node->key = temp->key;

            node->right = deleteNode(node->right, temp->key);
        }
        if (node == nullptr)
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;
        int bal = getBalance(node);

        //Left Left Case
        if (bal > 1 && key < node->left->key)
            return rightRotate(node);

        //Right Right Case
        if (bal < -1 && key > node->right->key)
            return leftRotate(node);

        //Left Right Case
        if (bal > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        //Right Left Case
        if (bal < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

int main() {
    Node* root = nullptr;
    int values[] = {10, 20, 30, 40, 50};

    for (int v : values) {
        cout << "Inserting " << v << endl;
        root = insert(root, v);
        cout << "Current preorder: ";
        preOrder(root);
        cout << endl;
    }
    cout << "Root key: " << root->key << endl;
    cout << "Root balance: " << getBalance(root) << endl;
    cout << "Root height: " << height(root) << endl;

    root = deleteNode(root, 10);

    cout << "\nFinal PreOrder: ";
    preOrder(root);
    cout << endl;

}
