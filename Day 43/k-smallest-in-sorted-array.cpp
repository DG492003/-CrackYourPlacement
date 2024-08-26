class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // Min-heap (priority queue) where each element is a tuple (value, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        // Initialize the heap with the first element of each row
        for (int i = 0; i < n; ++i) {
            minHeap.push({matrix[i][0], i, 0});
        }
        
        int count = 0;
        int result = 0;
        
        // Extract the minimum element k times
        while (count < k) {
            auto [val, row, col] = minHeap.top();
            minHeap.pop();
            result = val;
            count++;
            
            // If there is a next element in the same row, push it into the heap
            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }
        
        return result;
    }
};
