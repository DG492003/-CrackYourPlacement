// The time complexity is O(n), ensuring that the algorithm scales well with the input size.
// The space complexity is O(log n) due to the depth of the recursion stack, making it space-efficient.

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
    // Helper function to construct a height-balanced BST from a sorted array
    TreeNode* helper(vector<int>& arr, int s, int e) {
        // Base case: if start index exceeds end index, return nullptr
        if (s > e)
            return nullptr;
        
        // Find the middle element of the current subarray
        int mid = s + (e - s) / 2;
        
        // Create a new tree node with the middle element
        TreeNode* node = new TreeNode(arr[mid]);
        
        // Recursively build the left subtree using the left half of the current subarray
        node->left = helper(arr, s, mid - 1);
        
        // Recursively build the right subtree using the right half of the current subarray
        node->right = helper(arr, mid + 1, e);
        
        // Return the current node as the root of this subtree
        return node;
    }

public:
    // Function to convert a sorted array into a height-balanced BST
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        
        // If the array is empty, return nullptr (no tree can be formed)
        if (n == 0)
            return nullptr;
        
        // Start the recursive construction of the BST from the entire array
        TreeNode* root = helper(arr, 0, n - 1);
        
        // Return the root of the constructed BST
        return root;
    }
};
