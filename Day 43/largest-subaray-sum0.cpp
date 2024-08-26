class Solution {
public:
    int maxLen(vector<int>& nums) {
        unordered_map<int, int> prefixSumIndexMap;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];

            // If prefix sum is 0, update maxLength
            if (prefixSum == 0) {
                maxLength = i + 1;
            }

            // If prefix sum already exists, calculate the length of subarray
            if (prefixSumIndexMap.find(prefixSum) != prefixSumIndexMap.end()) {
                int length = i - prefixSumIndexMap[prefixSum];
                maxLength = max(maxLength, length);
            } else {
                // Store the index of the prefix sum if it's not already present
                prefixSumIndexMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};