// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree

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
    // Function to check if there is a path from root to leaf with a given sum
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the tree is empty, there is no path, so return false
        if (!root)
            return false;

        // Check if the current node is a leaf node and if the remaining target
        // sum is zero
        if (!root->left && !root->right && targetSum - root->val == 0)
            return true; // Path with the required sum found

        // Recursively check left and right subtrees with updated target sum
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
