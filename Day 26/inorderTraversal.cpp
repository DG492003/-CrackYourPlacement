// Time complexity: O(n)
// Space complexity: O(n) In the worst case, we have skewed tree.

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
public:
    // Public method to return the inorder traversal of a binary tree
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;    // Vector to store the result of inorder traversal
        inorder(root, res); // Helper function to perform the inorder traversal
        return res;         // Return the result vector
    }

private:
    // Private helper method for recursive inorder traversal
    void inorder(TreeNode* node, vector<int>& res) {
        // Base case: if the current node is null, return
        if (!node)
            return;
        inorder(node->left, res);  // Recursively traverse the left subtree
        res.push_back(node->val);  // Visit curr node and add value to result
        inorder(node->right, res); // Recursively traverse the right subtree
    }
};
