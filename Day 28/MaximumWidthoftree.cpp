// Time Complexity: O(N)
// Space Complexity: O(N)

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
    // Function to find the maximum width of a binary tree
    int widthOfBinaryTree(TreeNode* root) {
        // If the root is NULL, the width is 0
        if (root == NULL) {
            return 0;
        }

        long width = 0; // Variable to store the maximum width

        // Queue to perform level-order traversal
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0}); // Start with the root node at position 0

        while (!q.empty()) {
            long len = q.size(); // Number of nodes at the current level
            long start = q.front().second; // Start position of current level
            long end = q.back().second;    // End position of the current level

            // Update the maximum width based on the current level
            width = max(width, end - start + 1);

            // Traverse all nodes at the current level
            for (int i = 0; i < len; i++) {
                pair<TreeNode*, int> temp = q.front();
                q.pop();

                // Calculate the position of left child and push it to queue
                if (temp.first->left) {
                    q.push({temp.first->left, (long)2 * temp.second + 1});
                }

                // Calculate the position of right child and push it to queue
                if (temp.first->right) {
                    q.push({temp.first->right, (long)2 * temp.second + 2});
                }
            }
        }

        // Return the maximum width found
        return width;
    }
};