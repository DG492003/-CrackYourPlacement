// Time complexity: O(n)
// Space complexity: O(n)

// Recusrion approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: If the tree is empty, the depth is 0
        if (!root)
            return 0;

        // Recursively find the maximum depth of the left subtree
        int leftH = maxDepth(root->left);

        // Recursively find the maximum depth of the right subtree
        int rightH = maxDepth(root->right);

        // The depth of the current node is 1 plus the maximum of the depths of
        // its subtrees
        return 1 + max(leftH, rightH);
    }
};


// Level order approach
 int maxDepth(TreeNode* root) {
        //LEVEL ORDER 
            if(root==nullptr) return 0;
            queue<TreeNode *> q;
            q.push(root);
            int level=0;
            int n;
            while(!q.empty()){
                ++level;
                n=q.size();
                for(int i=0;i<n;i++){
                    root=q.front();
                    q.pop();
                    if(root->left!=nullptr) q.push(root->left);
                    if(root->right!=nullptr) q.push(root->right);
                }
            }
            return level;
    }