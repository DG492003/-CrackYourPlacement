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
    // Helper function to invert the binary tree
    void invert(TreeNode* root) {
        // Base case: if the node is null, return immediately
        if (!root)
            return;

        // Swap the left and right children of the current node
        TreeNode* temp =
            root->left; // Store the left child in a temporary variable
        root->left = root->right; // Assign the right child to the left child
        root->right = temp; // Assign the original left child to the right child

        // Recursively invert the left and right subtrees
        invert(root->left);
        invert(root->right);
    }

public:
    // Public method to be called for inverting the binary tree
    TreeNode* invertTree(TreeNode* root) {
        invert(root); // Start the inversion process
        return root;  // Return the root of the inverted tree
    }
};
