#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        if (start > end) return {NULL};

        vector<TreeNode*> result;

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};

void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution s;
    vector<TreeNode*> trees = s.generateTrees(3);

    for (auto tree : trees) {
        printPreorder(tree);
        cout << endl;
    }
}
