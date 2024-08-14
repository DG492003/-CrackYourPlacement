// Time Complexity:
//     O(N): The in-order traversal visits each node exactly once, where N is the number of nodes in the tree.
// Space Complexity:
//     O(N): The vector v stores all elements of BST, requiring space proportional to number of nodes in the tree.
//     Additionally, recursive call stack space could take up to O(H) space. In worst case (a skewed tree), H = N.

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

float findMedian(Node* root) {
    vector<int> v;
    inorder(root, v);
    
    int n = v.size();
    
    if (n == 0) {
        return 0.0;
    }
    
    if (n % 2 == 1) {
        int x = n / 2;
        return v[x];
    } else {
        int x = n / 2;
        int y = x - 1;
        return (v[x] + v[y]) / 2.0;
    }
}