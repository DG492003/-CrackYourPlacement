// Time Complexity: O(N+k⋅logN) (or) O(N+k⋅N) in the worst case
// Space Complexity: O(N).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // Stores ancestors of the target node along with direction info
    vector<pair<int, TreeNode*>> ancestors;
    // Stores the final nodes that are k distance away
    vector<int> ans;

    // Helper function to find all ancestors of the target node
    bool findancestors(TreeNode* root, TreeNode* target) {
        // Base case: If root is null, return false
        if (!root)
            return false;

        // If target node is found, push it to ancestors
        if (root == target) {
            ancestors.push_back({-1, root});
            return true;
        }

        // Recur on left and right subtrees
        bool right = findancestors(root->right, target);
        bool left = findancestors(root->left, target);

        // If target is found in left subtree, push root with 1 indicating
        // left child
        if (left)
            ancestors.push_back({1, root}); // 1 to signify left subtree

        // If the target is found in right subtree, push root with 0 indicating
        // right child
        if (right)
            ancestors.push_back({0, root}); // 0 to signify right subtree

        // Return true if target is found in either subtree
        return right || left;
    }

    // Helper function to find nodes at distance k from the given root
    void findans(TreeNode* root, int k, int depth, int child) {
        // Base case: If root is null, return
        if (!root)
            return;

        // If the current depth matches the desired distance k
        if (k == depth) {
            ans.push_back(root->val); // Add the node's value to the answer
            return;
        }

        // Depending on whether we are at the starting point or deeper, search
        // the opposite subtree

        // Search the right subtree if the target was in left subtree
        if (depth == 0 && child == 1)
            findans(root->right, k, depth + 1, child);
        // Search the left subtree if the target was in right subtree
        else if (depth == 0 && child == 0)
            findans(root->left, k, depth + 1, child);
        // If deeper, search both left and right subtrees
        else {
            findans(root->left, k, depth + 1, child);
            findans(root->right, k, depth + 1, child);
        }
    }

public:
    // Main function to find all nodes at distance k from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // First, find all ancestors of the target node
        findancestors(root, target);
        // For each ancestor, find nodes at distance k
        // Decrease k as we move up the ancestor chain
        for (auto [child, ptr] : ancestors) {
            findans(ptr, k, 0, child);
            k--;
        }
        return ans; // Return the list of nodes at distance k
    }
};