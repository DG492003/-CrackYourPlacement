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
public:
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are the same (both trees are empty at
        // this point)
        if (p == nullptr && q == nullptr)
            return true;

        // If one of the nodes is null and the other is not, the trees are not
        // the same
        if (p == nullptr || q == nullptr)
            return false;

        // Check if the current nodes' values are the same
        // and recursively check the left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
