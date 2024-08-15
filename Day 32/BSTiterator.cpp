// Time Complexity:
//     next(): Average O(1) (Amortized O(1) per call, O(n) over all calls)
//     hasNext(): O(1)
// Space Complexity: O(h), where h is the height of the tree.







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

class BSTIterator {
private:
    // Stack to store the nodes for in-order traversal
    stack<TreeNode*> mystack;

    // Helper function to push all left children of the node onto the stack
    void push_all(TreeNode* node) {
        // Traverse down the left side of the tree and push all nodes to the stack
        while (node != nullptr) {
            mystack.push(node);
            node = node->left;
        }
    }

public:
    // Constructor initializes the stack with the leftmost path of the tree
    BSTIterator(TreeNode* root) {
        push_all(root);
    }

    // Returns the next smallest element in the BST
    int next() {
        // Get the top node from the stack (which is the current smallest element)
        TreeNode* node = mystack.top();
        mystack.pop();

        // If the node has a right child, push all its left descendants to the stack
        push_all(node->right);

        // Return the value of the current smallest element
        return node->val;
    }

    // Returns true if there are more nodes to visit in the in-order traversal
    bool hasNext() {
        return !mystack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
