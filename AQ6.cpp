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

TreeNode* buildTreeRec2(int in[], int post[], int& postIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int rootVal = post[postIndex--];
    TreeNode* root = new TreeNode(rootVal);

    int pos = searchInorder(in, inStart, inEnd, rootVal);

    root->right = buildTreeRec2(in, post, postIndex, pos + 1, inEnd);
    root->left = buildTreeRec2(in, post, postIndex, inStart, pos - 1);

    return root;
}

TreeNode* buildTree2(int in[], int post[], int n) {
    int postIndex = n - 1;
    return buildTreeRec2(in, post, postIndex, 0, n - 1);
}

void printPre(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}

int main() {
    int inorder[]  = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = 5;

    TreeNode* root = buildTree2(inorder, postorder, n);

    printPre(root);
}
