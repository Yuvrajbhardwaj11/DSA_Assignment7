#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (!head) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    if (a->val < b->val) {
        head = tail = a;
        a = a->right;
    } else {
        head = tail = b;
        b = b->right;
    }

    while (a && b) {
        if (a->val < b->val) {
            tail->right = a;
            a->left = tail;
            tail = a;
            a = a->right;
        } else {
            tail->right = b;
            b->left = tail;
            tail = b;
            b = b->right;
        }
    }

    if (a) tail->right = a, a->left = tail;
    else if (b) tail->right = b, b->left = tail;

    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
}

int main() {
    Node* a = new Node(4);
    a->left = new Node(2);
    a->right = new Node(6);

    Node* b = new Node(5);
    b->left = new Node(1);
    b->right = new Node(7);

    Node *head1 = NULL, *prev1 = NULL;
    Node *head2 = NULL, *prev2 = NULL;

    bstToDLL(a, head1, prev1);
    bstToDLL(b, head2, prev2);

    Node* merged = mergeDLL(head1, head2);

    printDLL(merged);
}
