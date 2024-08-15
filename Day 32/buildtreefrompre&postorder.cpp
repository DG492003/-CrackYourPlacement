// Left Subtree:
//     postStart remains the same.
//     postEnd is decremented to exclude the root node.
//     preStart starts after the current root, and preEnd ends at the size of the left subtree.

// Right Subtree:
//     postStart moves to right after the left subtree.
//     postEnd adjusts to exclude both the left subtree and the current root node.
//     preStart starts after the left subtree in preorder, and preEnd remains the same.

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
    // Function to construct the tree
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // Create a hash map to store index of each element in post array
        unordered_map<int, int> postMap;
        for (int i = 0; i < post.size(); ++i)
            postMap[post[i]] = i;

        // Helper function to build the tree
        return buildTree(pre, 0, pre.size() - 1, post, 0, post.size() - 1, postMap);
    }

private:
    // Helper function to recursively construct the tree
    TreeNode* buildTree(const vector<int>& pre, int preSt, int preEn,
                        const vector<int>& post, int postSt, int postEn,
                        unordered_map<int, int>& postMap) {

        // Base case: If there are no elements to construct the tree
        if (preSt > preEn || postSt > postEn)
            return nullptr;

        // The first element in pre is the root of the tree
        TreeNode* root = new TreeNode(pre[preSt]);

        // If there is only one element, return it as the root
        if (preSt == preEn)
            return root;

        // The second element in pre is the root of the left subtree
        int leftSubtreeRootVal = pre[preSt + 1];

        // Find the index of the left subtree root in the post array using
        // the hash map
        int leftSubtreeRootIndexInPost = postMap[leftSubtreeRootVal];

        // Calculate the size of the left subtree
        int leftSubtreeSize = leftSubtreeRootIndexInPost - postSt + 1;

        // Recursively construct the left and right subtrees
        root->left = buildTree(pre, preSt + 1, preSt + leftSubtreeSize, post,
                               postSt, leftSubtreeRootIndexInPost, postMap);

        root->right = buildTree(pre, preSt + leftSubtreeSize + 1, preEn, post,
                      leftSubtreeRootIndexInPost + 1, postEn - 1, postMap);

        return root;
    }
};
