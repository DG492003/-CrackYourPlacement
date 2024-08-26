// Building the frequency map: O(n), where n is the number of elements in nums.
// Heap operations: Each insertion and deletion operation in the heap takes O(log k), and there are m unique elements in the map, so the total heap operations take O(m * log k).
// Total time complexity: O(n + m * log k), where m is the number of unique elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Use a min-heap to keep track of the top k frequent elements
        // The heap stores pairs of (frequency, element)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (const auto& [num, freq] : frequencyMap) {
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the element with the lowest frequency
            }
        }

        // Step 3: Extract the k most frequent elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        // The result contains the k most frequent elements
        return result;
    }
};