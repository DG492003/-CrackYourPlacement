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
class Solution
{
public:
    TreeNode *firstMistake =
        nullptr; // Pointer to the first node that was swapped
    TreeNode *secondMistake =
        nullptr; // Pointer to the second node that was swapped
    TreeNode *pre =
        nullptr; // Pointer to the previously visited node during traversal

    // Main function to recover the BST
    void recoverTree(TreeNode *root)
    {
        // Initialize pre with a node having the minimum possible value
        pre = new TreeNode(INT_MIN);

        inorder(root); // Perform in-order traversal to find the swapped nodes

        // Swap the values of the two mistaken nodes to correct the BST
        swap(firstMistake->val, secondMistake->val);
    }

    // Helper function to perform in-order traversal
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return; // Base case: if the node is null, return

        inorder(root->left); // Traverse the left subtree

        // Detect the first mistake
        if (firstMistake == nullptr && root->val < pre->val)
        {
            firstMistake = pre; // The first node that should have been greater
        }

        // Detect the second mistake
        if (firstMistake != nullptr && root->val < pre->val)
        {
            secondMistake =
                root; // The second node that should have been greater
        }

        pre = root; // Update pre to the current node

        inorder(root->right); // Traverse the right subtree
    }
};