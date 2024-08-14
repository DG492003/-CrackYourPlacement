// Algorithm:
//     Start from the root node with an initial range [1, ∞).
//     For each node, recursively check its left and right subtrees.
//     For the left child of the node, the valid range will be [l, node->data - 1].
//     For the right child of the node, the valid range will be [node->data + 1, r].
//     If at any node, l == r, return True, indicating a dead end.
//     If no such node exists, return False.

class Solution{
  public:
    // Utility function to check for dead end in the BST
    bool checkDeadEnd(Node* root, int min_val, int max_val) {
        if (!root)
            return false;
    
        // If the current node is a leaf node
        if (!root->left && !root->right) {
            // If the min_val equals max_val, then it's a dead end
            if (min_val == max_val)
                return true;
            return false;
        }
    
        // Recur for left and right subtrees
        return checkDeadEnd(root->left, min_val, root->data - 1) || 
               checkDeadEnd(root->right, root->data + 1, max_val);
    }
    
    // Function to check if there is a dead end in the BST
    bool isDeadEnd(Node* root) {
        // Start with the whole range [1, ∞)
        return checkDeadEnd(root, 1, INT_MAX);
    }
};