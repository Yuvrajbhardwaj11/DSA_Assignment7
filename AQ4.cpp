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
    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;
        if (level == res.size()) res.push_back(node->val);
        dfs(node->right, level + 1, res);
        dfs(node->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution s;
    vector<int> view = s.rightSideView(root);

    for (int x : view) cout << x << " ";
}
