#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int searchInorder(int in[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (in[i] == value) return i;
    }
    return -1;
}

TreeNode* buildTreeRec(int pre[], int in[], int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int rootVal = pre[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int pos = searchInorder(in, inStart, inEnd, rootVal);

    root->left = buildTreeRec(pre, in, preIndex, inStart, pos - 1);
    root->right = buildTreeRec(pre, in, preIndex, pos + 1, inEnd);

    return root;
}

TreeNode* buildTree(int pre[], int in[], int n) {
    int preIndex = 0;
    return buildTreeRec(pre, in, preIndex, 0, n - 1);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = 5;

    TreeNode* root = buildTree(preorder, inorder, n);

    printInorder(root);
}

