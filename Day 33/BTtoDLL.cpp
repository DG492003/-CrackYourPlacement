// Time Complexity: O(n)
// Space Complexity: O(h), where h is the height of the binary tree. This accounts for the space used by the recursion stack during the in-order traversal.

class Solution {
  public:
    // Helper function to perform in-order traversal and convert BT to DLL
    void convertToDLL(Node* root, Node*& prev, Node*& head) {
        if (root == NULL) return;
        
        // Recur on the left subtree
        convertToDLL(root->left, prev, head);
        
        // Process the current node
        if (prev == NULL) {
            // This condition is true only for the leftmost node (first node in in-order)
            head = root; // Set the head of the DLL
        } else {
            // Link the current node with the previous node
            root->left = prev;
            prev->right = root;
        }
        prev = root; // Move prev to the current node
        
        // Recur on the right subtree
        convertToDLL(root->right, prev, head);
    }
  
    Node* bToDLL(Node* root) {
        Node *prev = NULL, *head = NULL;
        convertToDLL(root, prev, head);
        return head; // Return the head of the DLL
    }
};
