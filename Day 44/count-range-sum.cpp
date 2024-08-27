class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        // Step 1: Compute prefix sums
        vector<long long> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        // Step 2: Create a sorted set of all potential sums
        // Include 0 for subarrays starting from index 0
        set<long long> sortedSums = {0};
        for (long long sum : prefixSum)
        {
            sortedSums.insert(sum);         // Current prefix sum
            sortedSums.insert(sum - lower); // sum - lower boundary
            sortedSums.insert(sum - upper); // sum - upper boundary
        }

        // Step 3: Compress the sums into a smaller range for segment tree indexing
        unordered_map<long long, int> compressed;
        int index = 0;
        for (long long num : sortedSums)
        {
            compressed[num] =
                index++; // Assign a unique index to each unique sum
        }

        // Step 4: Initialize the segment tree
        vector<int> segmentTree(4 * index, 0);

        int count = 0;
        // Step 5: Process each prefix sum to count valid range sums
        for (long long sum : prefixSum)
        {
            int left = compressed[sum - upper];                        // Lower index for querying
            int right = compressed[sum - lower];                       // Upper index for querying
            count += query(segmentTree, 1, 0, index - 1, left, right); // Count sums within range
            update(segmentTree, 1, 0, index - 1, compressed[sum]);     // Update the segment tree
        }

        return count; // Return the total count of valid range sums
    }

    // Step 6: Update the segment tree at a specific index
    void update(vector<int> &segmentTree, int node, int start, int end, int idx)
    {
        if (start == end)
        {
            segmentTree[node]++; // Increase count at the leaf node
        }
        else
        {
            int mid = start + (end - start) / 2;
            if (idx <= mid)
            {
                update(segmentTree, 2 * node, start, mid, idx); // Update the left child
            }
            else
            {
                update(segmentTree, 2 * node + 1, mid + 1, end, idx); // Update the right child
            }
            segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1]; // Recalculate the current node
        }
    }

    // Step 7: Query the segment tree for the sum within a range
    int query(vector<int> &segmentTree, int node, int start, int end, int left,
              int right)
    {
        if (left > end || right < start)
        {
            return 0; // No overlap
        }
        if (left <= start && right >= end)
        {
            return segmentTree[node]; // Total overlap
        }
        int mid = start + (end - start) / 2;
        // Partial overlap: Query both children
        return query(segmentTree, 2 * node, start, mid, left, right) +
               query(segmentTree, 2 * node + 1, mid + 1, end, left, right);
    }
};
