class NumArray {
private:
    vector<int> arr;  // To store the original array
    vector<int> Tree; // To store the segment tree

    // Function to build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node, store the original array element
            Tree[node] = arr[start];
        } else {
            // Recursively build the segment tree
            int mid = (start + end) / 2;
            build(node * 2, start, mid);             // Build the left child
            build(node * 2 + 1, mid + 1, end);       // Build the right child

            // Internal node, store the sum of the two children
            Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
        }
    }

    // Function to query the sum in the range [L, R]
    int query(int node, int start, int end, int L, int R) {
        if (end < L || R < start) {
            // No overlap
            return 0;
        }

        if (L <= start && end <= R) {
            // Total overlap
            return Tree[node];
        }

        // Partial overlap, query both halves
        int mid = (start + end) / 2;
        int left = query(node * 2, start, mid, L, R);
        int right = query(node * 2 + 1, mid + 1, end, L, R);

        // Return the sum of both halves
        return left + right;
    }

public:
    // Constructor to build the segment tree
    NumArray(vector<int>& nums) {
        arr = nums;
        Tree.resize(4 * nums.size()); // Resize the segment tree array
        if (!nums.empty()) {
            build(1, 0, arr.size() - 1); // Build the segment tree
        }
    }

    // Function to get the sum of elements in the range [L, R]
    int sumRange(int L, int R) {
        return query(1, 0, arr.size() - 1, L, R);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
