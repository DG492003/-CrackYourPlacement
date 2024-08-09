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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Vector to store result of level order traversal
        vector<vector<int>> ans;
        // If tree is empty, return an empty result
        if (!root)
            return ans;

        queue<TreeNode*> Q; // Queue to facilitate level order traversal (BFS)
        Q.push(root);       // Start with the root node

        // flag variable to check whether we go left to right or vice-versa
        bool isLtoR = true;

        // Continue until there are no more nodes to process
        while (!Q.empty()) {
            int size = Q.size(); // Number of nodes at the current level
            // Vector to store values of nodes at current level
            vector<int> level(size);
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = Q.front(); // Get the front node from the queue
                Q.pop(); // Remove the processed node from the queue

                // if we go left to right then fill the level with start else
                // from back
                int idx = (isLtoR) ? i : (size - i - 1);
                level[idx] = node->val;

                if (node->left) // If left child exists, push it to queue
                    Q.push(node->left);
                if (node->right) // If right child exists, push it to queue
                    Q.push(node->right);
            }
            // change the pattern
            isLtoR = !isLtoR;

            // Add the current level's values to the result
            ans.push_back(level);
        }
        return ans; // Return the result of level order traversal
    }
};