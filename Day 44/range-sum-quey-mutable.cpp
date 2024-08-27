class NumArray {
private:
    // Segment Tree to store the sums of the segments of the array
    vector<int> Tree;

    // Original array used to construct the segment tree
    vector<int> arr;

    // Function to build the segment tree
    void build(int node, int start, int end) {
        // If start equals end, it's a leaf node in the segment tree
        if (start == end) {
            Tree[node] = arr[start];
        } else {
            // Calculate the mid-point of the current segment
            int mid = (start + end) / 2;
            int left = node * 2;      // Left child index in the segment tree
            int right = node * 2 + 1; // Right child index in the segment tree

            // Recursively build the left and right children
            build(left, start, mid);
            build(right, mid + 1, end);

            // Internal node will have the sum of the left and right children
            Tree[node] = Tree[left] + Tree[right];
        }
    }

    // Function to query the sum in the range [L, R]
    int query(int node, int start, int end, int L, int R) {
        // If the current segment is completely outside the query range
        if (R < start || end < L)
            return 0;

        // If the current segment is completely inside the query range
        if (L <= start && end <= R)
            return Tree[node]; // Full overlap

        // If the current segment is partially inside and partially outside the
        // query range
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, L, R); // Query the left child
        int right =
            query(2 * node + 1, mid + 1, end, L, R); // Query the right child

        // Combine the results of the left and right children
        return left + right;
    }

    // Function to update a value at a specific index in the array
    void updated(int node, int start, int end, int index, int val) {
        // If start equals end, it's a leaf node in the segment tree
        if (start == end) {
            arr[start] = val; // Update the original array
            Tree[node] = val; // Update the segment tree node
        } else {
            // Calculate the mid-point of the current segment
            int mid = (start + end) / 2;

            // Update the left or right child depending on the index
            if (index <= mid) {
                updated(2 * node, start, mid, index, val);
            } else {
                updated(2 * node + 1, mid + 1, end, index, val);
            }

            // After updating the child, update the current node to reflect the
            // change
            Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
        }
    }

public:
    // Constructor to initialize the segment tree and build it using the input
    // array
    NumArray(vector<int>& nums) {
        arr = nums;
        Tree.resize(
            4 *
            nums.size()); // Resize the segment tree to accommodate all nodes
        if (!nums.empty()) {
            build(1, 0, nums.size() - 1); // Build the segment tree
        }
    }

    // Function to update the value at a given index
    void update(int index, int val) {
        if (!arr.empty()) {
            updated(1, 0, arr.size() - 1, index, val);
        }
    }

    // Function to get the sum of elements in the range [left, right]
    int sumRange(int left, int right) {
        if (arr.empty())
            return 0;
        return query(1, 0, arr.size() - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */