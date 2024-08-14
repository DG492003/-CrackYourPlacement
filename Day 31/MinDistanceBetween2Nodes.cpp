//  time complexity is O(n).

class Solution{
private:
    // Function to find the LCA of nodes a and b
    Node* findLCA(Node* root, int a, int b) {
        if (root == nullptr) return nullptr;
        if (root->data == a || root->data == b) return root;

        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);

        // If both sides return non-null, root is the LCA
        if (leftLCA && rightLCA) return root; 

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }

    // Function to calculate the distance from root to a given node
    int findDistanceFromRoot(Node* root, int data) {
        if (root == nullptr) return -1; // Node not found
        if (root->data == data) return 0; // Node found

        int leftDistance = findDistanceFromRoot(root->left, data);
        int rightDistance = findDistanceFromRoot(root->right, data);

        if (leftDistance != -1) return leftDistance + 1;
        if (rightDistance != -1) return rightDistance + 1;

        return -1; // Node not found in either subtree
    }
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        
        // Step 1: Find LCA of nodes a and b
        Node* lca = findLCA(root, a, b);

        // Step 2: Find the distance from LCA to a and from LCA to b
        int distanceA = findDistanceFromRoot(lca, a);
        int distanceB = findDistanceFromRoot(lca, b);

        // Step 3: Return the sum of distances as the minimum distance between a and b
        return distanceA + distanceB;
    }
};