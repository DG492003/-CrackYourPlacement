// Time complexity: O(N) where n is the number of nodes.
// Space complexity: O(N), auxiliary space.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    public:
        // Function to find the lowest common ancestor (LCA) of two nodes p and
        // q in a binary tree
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // Base case: If the current node is NULL, or if it matches either p
            // or q, return the current node
            if (!root || root == p || root == q)
                return root;

            // Recur for the left subtree
            TreeNode* left = lowestCommonAncestor(root->left, p, q);

            // Recur for the right subtree
            TreeNode* right = lowestCommonAncestor(root->right, p, q);

            // If one of the subtrees returns NULL, the LCA is in the other
            // subtree
            if (left == nullptr)
                return right; // LCA is in the right subtree
            
            else if (right == nullptr)
                return left; // LCA is in the left subtree
            
            else
                // If both left and right are non-NULL, the current node is LCA
                return root;
    }
};