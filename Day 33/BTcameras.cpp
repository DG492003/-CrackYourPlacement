// Consider a node in the tree.
// It can be covered by its parent, itself, its two children.
// Four options.

// Consider the root of the tree.
// It can be covered by left child, or right child, or itself.
// Three options.

// Consider one leaf of the tree.
// It can be covered by its parent or by itself.
// Two options.

// If we set a camera at the leaf, the camera can cover the leaf and its parent.
// If we set a camera at its parent, the camera can cover the leaf, its parent and its sibling.

// We can see that the second plan is always better than the first.
// Now we have only one option, set up camera to all leaves' parent.

// Here is our greedy solution:

// Set cameras on all leaves' parents, thenremove all covered nodes.
// Repeat step 1 until all nodes are covered.

// Explanation:
// Apply a recusion function dfs.
// Return 0 if it's a leaf.
// Return 1 if it's a parent of a leaf, with a camera on this node.
// Return 2 if it's coverd, without a camera on this node.

// For each node,
// if it has a child, which is leaf (node 0), then it needs camera.
// if it has a child, which is the parent of a leaf (node 1), then it's covered.

// If it needs camera, then res++ and we return 1.
// If it's covered, we return 2.
// Otherwise, we return 0.

/**
 * 
 * Time Complexity: O(N), where N is the number of nodes in the tree.
    Space Complexity: O(H), where H is the height of the tree (worst-case O(N), best-case O(log N)).
 * 
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
    // Helper function to determine the state of the tree and count cameras
    int minCameraCoverHelper(TreeNode* root, int& cam) {
        // If the node is NULL, it's considered covered (no need
        // for a camera)
        if (root == NULL)
            return 1;

        // Recursively traverse the left and right subtrees
        int left = minCameraCoverHelper(root->left, cam);
        int right = minCameraCoverHelper(root->right, cam);

        // If either left or right child is not covered by a camera (i.e., they
        // return 0), place a camera at the current node.
        if (!(left && right)) {
            cam++;    // Increment the camera count
            return 2; // Return 2 to indicate that this node has a camera
        }

        // If the current node doesn't need a camera but is covered by its
        // children, return 1 to indicate it's covered.
        return max(left, right) - 1;
    }

    // Main function to determine the minimum number of cameras needed
    int minCameraCover(TreeNode* root) {
        // If the tree is empty, no cameras are needed
        if (root == NULL)
            return 0;

        int cam = 0; // Initialize camera count

        // If the root itself is not covered, add a camera
        if (!minCameraCoverHelper(root, cam))
            cam++;

        return cam; // Return the total number of cameras needed
    }
};
