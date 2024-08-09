// Time Complexity: O(log2N)
// Space Complexity : O(log2N) 


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
    // Recursive function to traverse the binary tree and populate the
    // right-side view
    void recursionRight(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) // If the current node is null, return
            return;

        // If the current level is equal to the size of the result vector,
        // it means we are visiting this level for the first time.
        if (result.size() == level) {
            // Add the current node's value to the result
            result.push_back(root->val);
        }

        // Recursively traverse the right subtree first, then the left subtree
        recursionRight(root->right, level + 1, result);
        recursionRight(root->left, level + 1, result);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; // Vector to store the right-side view

        // Start the recursion with the root node at level 0
        recursionRight(root, 0, result);

        return result; // Return the final right-side view
    }
};
