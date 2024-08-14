// Time complexity:O(n)
// Space complexity:O(h)

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
    // In-order traversal function to find the minimum difference
    void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (node == nullptr)
            return; // Base case: if the node is null, return

        // Traverse the left subtree
        inorder(node->left, prev, minDiff);

        // Process the current node
        if (prev != nullptr) {
            // Calculate the difference between the current node and the
            // previous node
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node; // Update prev to the current node

        // Traverse the right subtree
        inorder(node->right, prev, minDiff);
    }

    // Main function to initiate the process and return the minimum difference
    int getMinimumDifference(TreeNode* root) {
        // Pointer to keep track of the previous node in the in-order traversal
        TreeNode* prev = nullptr;
        int minDiff = INT_MAX; // Variable to store the minimum difference
        inorder(root, prev, minDiff); // Start the in-order traversal
        return minDiff;               // Return the minimum difference found
    }
};
