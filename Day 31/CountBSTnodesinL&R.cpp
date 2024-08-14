class Solution{
private:
private:
    // Helper function to calculate the sum of nodes within the given range
    int countBSTnodes(Node* root, int low, int high, int& count) {
        if (!root) // Base case: if the node is null, return
            return 0;

        // If the current node's value is within the range, add it to the count
        if (root->data >= low && root->data <= high)
            count++;

        // Recurse on the left subtree
        // No need to traverse left if root->val is less
        // than or equal to low
        if (root->data > low)
            countBSTnodes(root->left, low, high, count);

        // Recurse on the right subtree
        // No need to traverse right if root->val is
        // greater than or equal to high
        if (root->data < high)
            countBSTnodes(root->right, low, high, count);
            
        return count;
    }
public:
    int getCount(Node *root, int l, int h){
      // your code goes here   
      if(!root) 
        return 0;
      int count = 0;
      return countBSTnodes(root, l, h, count);
    }
};