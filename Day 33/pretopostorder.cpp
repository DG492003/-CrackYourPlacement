// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
  public:
    // Helper function to construct the BST from the given preorder traversal
    Node *helper(int pre[], int &n, int &index, int l, int h) {
        // Base case: if the index exceeds the number of elements, return NULL
        if (index >= n) return NULL;
        
        // If the current value doesn't fit in the allowed range (l, h), return NULL
        if (l > pre[index] or pre[index] > h) {
            return NULL;
        }
        
        // Create a new node with the current value and increment the index
        Node *root = newNode(pre[index++]);
        
        // Recursively construct the left subtree with the allowed range (l, root->data)
        root->left = helper(pre, n, index, l, root->data);
        
        // Recursively construct the right subtree with the allowed range (root->data, h)
        root->right = helper(pre, n, index, root->data, h);
        
        // Return the constructed subtree rooted at 'root'
        return root;
    }

    // Function that constructs a BST from its preorder traversal.
    Node* Bst(int pre[], int n) {
        // If the array is empty, return NULL
        if (n == 0) return NULL;
        
        // Initialize the index to 0 and call the helper function
        int i = 0;
        return helper(pre, n, i, 0, INT_MAX);
    }
};