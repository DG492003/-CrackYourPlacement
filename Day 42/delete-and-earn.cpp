// memoization
class Solution {
private:
    int MaxUtil(unordered_map<int, int> freq, vector<int> dp, int i) {
        // Base case: if index is less than 0, return 0
        if (i <= 0)
            return 0;

        // Check if the result is already computed
        if (dp[i] != -1)
            return dp[i];

        int take = (i > 1 ? MaxUtil(freq, dp, i - 2) : 0) + i * freq[i];
        int skip = MaxUtil(freq, dp, i - 1);

        // Store and return the maximum of taking or skipping the current number
        return dp[i] = max(take, skip);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        // Frequency map
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        // Find the maximum value in nums to determine the range of numbers we
        // need to consider
        int maxNum = *max_element(nums.begin(), nums.end());

        // Dynamic programming table
        vector<int> dp(maxNum + 1, -1);

        return MaxUtil(freq, dp, maxNum);
    }
};



// tabulation
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Frequency map
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        // Find the maximum value in nums to determine the range of numbers we
        // need to consider
        int maxNum = *max_element(nums.begin(), nums.end());

        // Dynamic programming table
        vector<int> dp(maxNum + 1, 0);

        // Initialize the dp table
        dp[1] = freq[1];

        for (int i = 2; i <= maxNum; ++i) {
            // Calculate dp[i]: the maximum points we can earn by considering up
            // to number i
            dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
        }

        return dp[maxNum];
    }
};