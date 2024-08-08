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
    // Helper function to calculate the depth of the tree
    // and update the diameter at the same time
    int maxDepth(TreeNode* root, int& diameter) {
        // Base case: If the tree is empty, the depth is 0
        if (!root)
            return 0;

        // Recursively find the maximum depth of the left subtree
        int leftH = maxDepth(root->left, diameter);

        // Recursively find the maximum depth of the right subtree
        int rightH = maxDepth(root->right, diameter);

        // Update the diameter if the path through the current node is larger
        // The path goes through the current node, which connects the left and
        // right subtrees
        diameter = max(diameter, leftH + rightH);

        // The depth of the current node is 1 plus the maximum of the
        // depths of its left and right subtrees
        return 1 + max(leftH, rightH);
    }

public:
    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;         // Initialize diameter
        maxDepth(root, diameter); // Call helper function to calculate diameter
        return diameter;          // Return the final diameter
    }
};