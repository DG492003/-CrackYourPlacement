// TC - O(n)
// SC - O(h)

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
    // Helper function to perform Inorder Traverasal
    void getPath(TreeNode* root, string path, vector<string>& res) {
        // If current node is a leaf, add path to result
        if (root->left == NULL && root->right == NULL)
            res.push_back(path);

        // Recur on the left child
        if (root->left != NULL)
            getPath(root->left, path + "->" + to_string(root->left->val), res);

        // Recur on the right child
        if (root->right != NULL)
            getPath(root->right, path + "->" + to_string(root->right->val), res);
    }

public:
    // Function to return all paths from root to leaf as strings
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res; // to store all paths from root to leaf as strings
        if (root != NULL) {
            string path = to_string(root->val); // Start with root node's data
            getPath(root, path, res); // Perform inorder to explore all paths
        }
        return res;
    }
};