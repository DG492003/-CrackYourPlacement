// Time Complexity: O(n) where n is the number of nodes in the tree.
// Space Complexity: O(n) in the worst case (for both the hash map and recursion stack).

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
    // Depth-First Search (DFS) function to explore all paths
    void dfs(TreeNode* root, int targetSum, long prefix_sum,
             unordered_map<long, int>& mp, int& count) {
        // Base case: If the current node is null, return immediately
        if (!root)
            return;

        // Update the prefix sum by adding the current node's value
        prefix_sum += root->val;

        // Check if there is a prefix sum that satisfies the condition
        // If (prefix_sum - targetSum) exists in the map, it means there is a
        // sub-path that sums to targetSum, so we add the frequency of that sum
        // to the count
        if (mp.find(prefix_sum - targetSum) != mp.end()) {
            count += mp[prefix_sum - targetSum];
        }

        // Increment the frequency of the current prefix sum in the map
        mp[prefix_sum]++;

        // Recur on the left and right children of the current node
        dfs(root->left, targetSum, prefix_sum, mp, count);
        dfs(root->right, targetSum, prefix_sum, mp, count);

        // Backtrack: Decrement the frequency of the current prefix sum
        // This ensures that the current node's contribution is removed before
        // returning to the parent node, allowing the map to reflect the correct
        // prefix sums for other paths
        mp[prefix_sum]--;
    }

public:
    // Main function to initiate the DFS and return the total count of paths
    int pathSum(TreeNode* root, int targetSum) {
        // Hash map to store prefix sums and their frequencies
        unordered_map<long, int> mp;

        // Initialize map with a base case: prefix sum 0 with frequency of 1
        mp[0] = 1;

        // Variable to store the total count of valid paths
        int count = 0;

        // Start the DFS from the root node with an initial prefix sum of 0
        dfs(root, targetSum, 0, mp, count);

        // Return the total count of paths that sum to targetSum
        return count;
    }
};
