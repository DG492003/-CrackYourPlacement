// TC - O(n) SC - O(n)

/**
 * Definition for root1 binary tree node.
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
    // Main function to merge two binary trees
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, return nullptr
        if (!root1 && !root2)
            return nullptr;

        // If one of the nodes is null, return the other node
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        // If both nodes are non-null, merge their values
        root1->val += root2->val;

        // Recursively merge the left and right subtrees
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        // Return the merged tree rooted at node 'root1'
        return root1;
    }
};
