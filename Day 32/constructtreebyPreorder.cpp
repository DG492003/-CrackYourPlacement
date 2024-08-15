/*
N = 5
pre[] = {10, 30, 20, 5, 15}
preLN[] = {N, N, L, L, L}


Time Complexity: O(n), where n is the number of nodes. Each node is processed exactly once.
Space Complexity: O(h), where h is the height of the tree, due to the recursion stack. In the worst case (skewed tree), this can be O(n).
*/


// Helper function to recursively construct the tree
Node* constructTreeHelper(int n, int pre[], char preLN[], int& index) {
    // Base case: if index is out of bounds
    if (index >= n) return nullptr;

    // Create the current node
    Node* root = new Node(pre[index]);

    // Check if the current node is a leaf node
    if (preLN[index] == 'L') {
        // Leaf node, has no children
        root->left = nullptr;
        root->right = nullptr;
    } else {
        // Non-leaf node, recursively construct the left and right subtrees
        index++; // Move to the next index for the left child
        root->left = constructTreeHelper(n, pre, preLN, index);

        index++; // Move to the next index for the right child
        root->right = constructTreeHelper(n, pre, preLN, index);
    }

    return root;
}
// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[]){
    // Code here
    int index = 0; // Initialize the index for the preorder and preLN arrays
    return constructTreeHelper(n, pre, preLN, index);
}