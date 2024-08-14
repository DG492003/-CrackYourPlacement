// Both Complexity:
// Worst-case time complexity: O(N) (when all nodes are within the range or the tree is a linked list).
// Best-case time complexity: O(log N) (when the tree is balanced and most nodes are outside the range).

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
    // Helper function to calculate the sum of nodes within the given range
    void sumBST(TreeNode* root, int low, int high, int& sum) {
        if (!root) // Base case: if the node is null, return
            return;

        // If the current node's value is within the range, add it to the sum
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // Recurse on the left subtree
        // No need to traverse left if root->val is less
        // than or equal to low
        if (root->val > low)
            sumBST(root->left, low, high, sum);

        // Recurse on the right subtree
        // No need to traverse right if root->val is
        // greater than or equal to high
        if (root->val < high)
            sumBST(root->right, low, high, sum);
    }

public:
    // Main function to initiate the sum calculation
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        sumBST(root, low, high, sum); // Call the helper function
        return sum;                   // Return the final sum
    }
};
