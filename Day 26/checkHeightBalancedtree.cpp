// Time complexity: O(n)
// Space complexity: O(n)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    // Helper function to calculate the height of the tree
    // and determine if the tree is balanced
    int checkHeight(TreeNode* node) {
        // Base case: If tree is empty, height is 0, and it's balanced
        if (!node)
            return 0;

        // Recursively find the maximum depth of the left subtree
        int leftH = checkHeight(node->left);
        if (leftH == -1) // If the left subtree is not balanced, return -1
            return -1;

        // Recursively find the maximum depth of the right subtree
        int rightH = checkHeight(node->right);
        if (rightH == -1) // If the right subtree is not balanced, return -1
            return -1;

        // If the current node is unbalanced, return -1
        if (abs(leftH - rightH) > 1)
            return -1;

        // If the current node is balanced, return its height
        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(TreeNode* root) {
        // The tree is balanced if the helper function doesn't return -1
        return checkHeight(root) != -1;
    }
};