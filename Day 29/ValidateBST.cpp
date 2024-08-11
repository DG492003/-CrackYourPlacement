// The time complexity of this function is O(n)
// Space complexity is O(h)

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
    // Helper function to validate the BST
    bool Isvalid(TreeNode* root, long min_val, long max_val) {
        // Base case: An empty tree is a valid BST
        if (!root)
            return true;

        // If the current node's value is outside the allowed range, return
        // false
        if (root->val >= max_val || root->val <= min_val)
            return false;

        // Recursively check the left and right subtrees
        // For the left subtree, the max allowed value is the current node's
        // value For the right subtree, the min allowed value is the current
        // node's value
        return Isvalid(root->left, min_val, root->val) &&
               Isvalid(root->right, root->val, max_val);
    }

public:
    // Public function to check if the entire tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial min and max values
        // Use LONG_MIN and LONG_MAX to represent the range of valid values
        return Isvalid(root, LONG_MIN, LONG_MAX);
    }
};
