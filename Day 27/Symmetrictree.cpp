// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. 
// Space Complexity: O(1) as no additional data structures or memory is allocated. O(H): Recursive Stack Space

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
    // Function to check if
    // two subtrees are symmetric
    bool isSymmetricUtil(TreeNode* root1, TreeNode* root2) {
        // Check if either subtree is NULL
        if (root1 == NULL || root2 == NULL) {
            // If one subtree is NULL, the other
            // must also be NULL for symmetry
            return root1 == root2;
        }
        // Check if the val in the current nodes is equal
        // and recursively check for symmetry in subtrees
        return (root1->val == root2->val) &&
               isSymmetricUtil(root1->left, root2->right) &&
               isSymmetricUtil(root1->right, root2->left);
    }

public:
    // Public function to check if the
    // entire binary tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // Check if the tree is empty
        if (!root) {
            // An empty tree is
            // considered symmetric
            return true;
        }
        // Call the utility function
        // to check symmetry of subtrees
        return isSymmetricUtil(root->left, root->right);
    }
};