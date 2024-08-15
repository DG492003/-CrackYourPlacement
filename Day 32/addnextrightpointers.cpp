/* time complexity O(n)


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Function to connect all nodes at the same level in a perfect binary tree
    Node* connect(Node* root) {
        if (!root)
            return nullptr; // Base case: if the root is null, return nullptr

        // Local pointers for left child, right child, and next node
        auto L = root->left;  // Left child of the root
        auto R = root->right; // Right child of the root
        auto N = root->next;  // Next node of the root

        // Connect the next pointer for the left child
        if (L) {
            // The next pointer of the left child should point to
            // the right child
            L->next = R;

            // If the root has a next node, connect the right child's next
            // pointer
            if (N) {
                // The next pointer of the right child should
                // point to the left child of the root's next
                R->next = N->left;
            }

            // Recursively connect the left and right subtrees
            connect(L); // Connect the left subtree
            connect(R); // Connect the right subtree
        }

        return root; // Return the root after connecting all the nodes
    }
};