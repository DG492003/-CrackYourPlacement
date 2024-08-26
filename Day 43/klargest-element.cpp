// Inserting an element into the heap: O(log k)
// Removing the top element from the heap: O(log k)
// Total time complexity: O(n * log k)
// Total space complexity: O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Define a min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Iterate through each element in the array `nums`
        for (auto i : nums) {
            // Push the current element into the min-heap
            minHeap.push(i);

            // If the size of the heap exceeds `k`, remove the smallest element
            // This keeps the heap size exactly `k`, containing the largest `k`
            // elements seen so far
            if (minHeap.size() > k)
                minHeap.pop();
        }

        // The top element of min-heap is the `k`-th largest element in array
        return minHeap.top();
    }
};