// Time Complexity: O(N) where N is the number of nodes in the Binary Tree
// Space Complexity: O(1) as no additional space size of the tree. O(H) Recursive Stack Auxiliary Space 

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
    // Helper function to calculate the maximum path sum and update the maxSum
    int maxDepth(TreeNode* root, int& maxSum) {
        // Base case: If the tree is empty, the depth is 0
        if (!root)
            return 0;

        // Recursively find the maximum path sum of the left subtree
        // Only consider positive sums; if the sum is negative, ignore it
        int leftSum = max(0, maxDepth(root->left, maxSum));

        // Recursively find the maximum path sum of the right subtree
        // Only consider positive sums; if the sum is negative, ignore it
        int rightSum = max(0, maxDepth(root->right, maxSum));

        // Update the maximum path sum considering the path that passes through
        // the current node
        maxSum = max(maxSum, root->val + leftSum + rightSum);

        // Return the maximum path sum that extends to the parent node
        return root->val + max(leftSum, rightSum);
    }

public:
    // Function to calculate the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize to smallest possible integer value
        // Call helper function to calculate maximum path sum
        maxDepth(root, maxSum);
        return maxSum; // Return the maximum path sum found
    }
};
