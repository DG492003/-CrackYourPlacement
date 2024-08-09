/*
Step 1: Create an empty map to store the nodes based on their vertical and horizontal levels.The key of the map ‘x’ represents the vertical column, and the nested map uses ‘y’ as the key for the level. Initialise a ‘multiset’ to store node values at a specific vertical and level to ensure unique and sorted order of nodes.
Step 2: Initialise a queue for level order BFS traversal. Each element in the queue should be a pair containing the current node and its vertical and level order information as x and coordinates. Enqueue the root node into the queue with its initial vertical and level order values as (0, 0)
Step 3: While the queue is not empty, pop the front node of the queue:
    Get this nodes vertical ie. ‘x’ and level order ‘y’ information.
    Insert this node into the map at its corresponding coordinate.
    Push the left and right child of the node with their updated horizontal distance and level order.
Step 4: After the BFS traversal using the queue is complete, initialise a final result 2D vector ‘ans’. 


Time Complexity: O(N * log2N * log2N * log2N) 
    Traversal performed using BFS as a time complexity of O(N) 
    Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
    Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).

Space Complexity: O(N + N/2)
    The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) as it stores all N nodes of the Binary Tree.
    The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    /*
    details about structures
    node{
        int -> vertical order
        map<int,multiset> -> level order and multiset to store node values at a
        specific vertical and level to ensure unique and sorted order of nodes.
    }

    Q{
        node -> node
        pair<int,int>-> vertical and level order
    }
   col.insert(col.end(), q.second.begin(), q.second.end()); this line means->

    For example, if col originally contained [1, 2, 3] and q.second contained
    [4, 5], after this operation, col would contain [1, 2, 3, 4, 5].
*/
public:
    // Function to perform vertical order traversal
    // and return a 2D vector of node values
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes based on
        // vertical and level information
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical and level information
        queue<pair<TreeNode*, pair<int, int>>> Q;

        // Push the root node with initial vertical
        // and level values (0, 0)
        Q.push({root, {0, 0}});

        // BFS traversal
        while (!Q.empty()) {
            // Retrieve the node and its vertical
            // and level information from
            // the front of the queue
            auto p = Q.front();
            Q.pop();
            TreeNode* temp = p.first;

            // Extract the vertical and level information
            // x -> vertical
            int x = p.second.first;
            // y -> level
            int y = p.second.second;

            // Insert the node value into the
            // corresponding vertical and level
            // in the map
            nodes[x][y].insert(temp->val);

            // Process left child
            if (temp->left) {
                // Move left in terms of vertical
                // Move down in terms of level
                Q.push({temp->left, {x - 1, y + 1}});
            }

            // Process right child
            if (temp->right) {
                // Move right in terms of vertical
                // Move down in terms of level
                Q.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Prepare the final result vector
        // by combining values from the map
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};