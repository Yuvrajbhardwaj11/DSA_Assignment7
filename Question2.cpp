#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = NULL; }
};

Node* insert(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right) return findMin(node->right);
    Node* succ = NULL;
    while (root) {
        if (node->data < root->data) { succ = root; root = root->left; }
        else if (node->data > root->data) root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left) return findMax(node->left);
    Node* pred = NULL;
    while (root) {
        if (node->data > root->data) { pred = root; root = root->right; }
        else if (node->data < root->data) root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    Node* s1 = searchRecursive(root, 40);
    Node* s2 = searchNonRecursive(root, 60);
    cout << (s1 ? s1->data : -1) << endl;
    cout << (s2 ? s2->data : -1) << endl;
    cout << findMax(root)->data << endl;
    cout << findMin(root)->data << endl;
    cout << inorderSuccessor(root, s1)->data << endl;
    cout << inorderPredecessor(root, s2)->data << endl;
}
