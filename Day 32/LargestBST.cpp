// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once.
// Space Complexity: O(h), where h is the height of tree, due to the recursion stack. Inworst case, this is O(n).

class Solution{
    public:
    // Function to determine the size of the largest BST subtree
    vector<int> solve(Node* root, int& ans) {
        if (!root)
            // If the node is null, return a vector indicating an empty subtree
            return {0, INT_MAX, INT_MIN};

        // Recursively get the information for left and right subtrees
        vector<int> l = solve(root->left, ans);  // l[0] = size of BST, l[1] = min value, l[2] = max value for left subtree
        vector<int> r = solve(root->right, ans); // r[0] = size of BST, r[1] = min value, r[2] = max value for right subtree

        // Check if both left and right subtrees are BSTs
        if (l[0] >= 0 && r[0] >= 0) {
            // Ensure the current node's value is greater than the max value of the left subtree
            if (root->left && root->data <= l[2]) {
                return {-1, -1, -1}; // Return an invalid result if the BST property is violated
            }
            // Ensure the current node's value is less than the min value of the right subtree
            if (root->right && root->data >= r[1]) {
                return {-1, -1, -1}; // Return an invalid result if the BST property is violated
            }
            // Calculate the minimum and maximum values for the current subtree
            int mi = min(l[1], root->data); // Minimum value in the current subtree
            int mx = max(r[2], root->data); // Maximum value in the current subtree

            // Update the size of the largest BST subtree found
            ans = max(ans, l[0] + r[0] + 1);

            // Return the size, minimum value, and maximum value of the current subtree
            return {l[0] + r[0] + 1, mi, mx};
        }
        // Return an invalid result if the current subtree is not a BST
        return {-1, -1, -1};
    }

    // Function to return the size of the largest subtree which is a BST
    int largestBst(Node* root) {
        int ans = 0;  // Variable to store the size of the largest BST subtree found
        solve(root, ans); // Call the solve function to populate the `ans` variable
        return ans;  // Return the size of the largest BST subtree
    }
};