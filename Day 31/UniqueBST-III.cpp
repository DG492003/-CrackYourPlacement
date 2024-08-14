// TC - O(4^N/Sqrt(N))
// SC - O(4^N/Sqrt(N))

// Steps to Solve the Problem:
//     Choose a Root: For each number i from 1 to n, consider it as the root.
//     Generate Left and Right Subtrees:
//         The left subtree will be formed from the numbers [1, i-1].
//         The right subtree will be formed from the numbers [i+1, n].
//     Combine Trees:
//         For each root i, combine each left subtree with each right subtree to form a BST with i as the root.
//     Recursion:
//         Recursively apply the above steps to generate all possible subtrees for each root.
//     Base Case:
//         If start > end, return an empty subtree (i.e., nullptr).

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
    vector<TreeNode*> buildTree(int start, int end) {
        vector<TreeNode*> ans;

        // If start > end, then subtree will be empty so add NULL in the ans and
        // return it.
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        // Iterate through all values from start to end to construct left and
        // right subtree recursively
        for (int i = start; i <= end; ++i) {

            // Construct left subtree
            vector<TreeNode*> leftSubTree = buildTree(start, i - 1);
            // Construct right subtree
            vector<TreeNode*> rightSubTree = buildTree(i + 1, end);

            // loop through all left and right subtrees and connect them to ith
            // root
            for (int j = 0; j < leftSubTree.size(); j++) {
                for (int k = 0; k < rightSubTree.size(); k++) {
                    // Create root with value i
                    TreeNode* root = new TreeNode(i);

                    // Connect left subtree rooted at leftSubTree[j]
                    root->left = leftSubTree[j];
                    // Connect right subtree rooted at rightSubTree[k]
                    root->right = rightSubTree[k];
                    // Add this tree(rooted at i) to ans data-structure
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) { return buildTree(1, n); }
};