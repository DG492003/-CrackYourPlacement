// Time Complexity: The time complexity remains O(N),

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    // Helper function to calculate the sum of left leaves
    void sumLeftLeaves(TreeNode* root, int& sum) {
        if (!root)  // Base case: if the node is null, return
            return;

        // Check if the left child is a leaf
        if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;  // Add the value of the left leaf to sum
        }

        // Recurse on the left subtree
        sumLeftLeaves(root->left, sum);

        // Recurse on the right subtree
        sumLeftLeaves(root->right, sum);
    }

public:
    // Main function to initiate the sum calculation of left leaves
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumLeftLeaves(root, sum);  // Call the helper function
        return sum;  // Return the final sum of left leaves
    }
};
