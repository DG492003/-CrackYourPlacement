// Time Complexity: O(h), where h is the height of the tree
// Space Complexity: O(h) due to the recursion stack

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is nullptr, there's no tree to search, so return
        // nullptr
        if (!root)
            return nullptr;

        // If both p and q are less than the root, LCA must be in the left
        // subtree
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // If both p and q are greater than the root, LCA must be in the right
        // subtree
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // If neither of the above cases is true, then the current root is the
        // LCA
        return root;
    }
};