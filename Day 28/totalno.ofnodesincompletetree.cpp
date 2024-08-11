/*
Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.
    -> The calculation of leftHeight and rightHeight takes O(log N) time.
    -> In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).
    -> Therefore, the total time complexity is O(log N * log N).

Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.
    -> The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
    -> Since the given tree is a complete binary tree, the height will always be log N.
    -> Therefore, the space complexity is O(log N).

Approach ->
Maximum Number of Nodes: 2^h-1
To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.
    If the left height equals right height, it indicates that the last level is completely filled.
    If the left height does not equal right height, the last level is not completely filled.
*/

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
    // Function to find the height of a tree
    int findHeight(TreeNode* node, bool direction) {
        int height = 0;
        // Traverse child until
        // reaching the leftmost leaf
        while (node) {
            height++;
            // if direction is 1 we traverse only right tree else only left tree
            node = direction ? node->right : node->left;
        }
        return height;
    }

public:
    // Function to count nodes in a binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root
        // is NULL, there are no nodes
        if (root == NULL)
            return 0;

        // Find the left height and
        // right height of the tree
        int lh = findHeight(root, 0);
        int rh = findHeight(root, 1);

        // Check if the last level
        // is completely filled
        if (lh == rh)
            // If so, use the formula for
            // total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1 << lh) - 1;

        // If the last level is not completely
        // filled, recursively count nodes in
        // left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};