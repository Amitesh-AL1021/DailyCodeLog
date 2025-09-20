#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node (only needed for local testing)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, false);
    }

private:
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) return 0;

        // If it's a leaf node and a left child
        if (!node->left && !node->right && isLeft) {
            return node->val;
        }

        // Recurse for left and right children
        return dfs(node->left, true) + dfs(node->right, false);
    }
};

// Helper function to build a sample test tree
TreeNode* buildTree() {
    /*
        Example Tree:
            3
           / \
          9  20
             /  \
            15   7
        Expected output = 9 + 15 = 24
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    cout << "Sum of left leaves: " << sol.sumOfLeftLeaves(root) << endl;

    return 0;
}
