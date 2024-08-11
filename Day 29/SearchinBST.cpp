// Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

// Space Complexity: O(1) since the algorithm does not use any additional space or data structures. The algorithm does use auxiliary stack space from recursion. In the average and worst-case scenarios, the space complexity for recursive stack space is O(h), where 'h' represents the height of the tree.


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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Loop until the root is NULL (meaning we've reached a leaf node)
        // or until we find the node with the value we're looking for
        while (root != nullptr && root->val != val) {
            // If the value we're looking for is smaller than the current node's
            // value,
            // move to the left child
            // If the value we're looking for is greater than the current node's
            // value,
            // move to the right child
            root = val < root->val ? root->left : root->right;
        }

        // If we exit the loop, root will either be NULL (if the value wasn't
        // found),
        // or it will be the node containing the value we're looking for
        return root;
    }
};