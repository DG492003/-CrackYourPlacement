// time complexity of the findPreSuc function is O(h) + O(h) = O(h).
// Space Complexity: O(1).


class Solution {
private:
    // Function to find the successor of a given key
    Node* successor(Node* root, int key) {
        Node* suc = nullptr;
        while (root) {
            if (root->key <= key) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }

    // Function to find the predecessor of a given key
    Node* predecessor(Node* root, int key) {
        Node* pre = nullptr;
        while (root) {
            if (root->key >= key) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }
        return pre;
    }

public:
    // Function to find both predecessor and successor of a given key
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        // Find the successor
        suc = successor(root, key);
        // Find the predecessor
        pre = predecessor(root, key);
    }
};
