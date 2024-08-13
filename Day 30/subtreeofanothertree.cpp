// time complexity is O(m * n)
// space complexity is O(h)

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
    // Helper function to check if two trees are identical
    bool isSameTree(TreeNode* s, TreeNode* t) {
        // If both nodes are null, they are identical
        if (!s && !t)
            return true;
        // If one of the nodes is null, or the values are different, they are
        // not identical
        if (!s || !t || s->val != t->val)
            return false;
        // Recursively check the left and right subtrees
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

public:
    // Function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If subRoot is null, it's a subtree of any tree
        if (!subRoot)
            return true;
        // If root is null, but subRoot isn't, subRoot can't be a subtree
        if (!root)
            return false;

        // Check if the current subtree matches subRoot, or check in left or
        // right subtrees
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
