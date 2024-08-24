// memoization
class Solution {
private:
    // Function to find the length of the longest increasing subsequence
    int getAns(vector<int>& arr, int n, int ind, int prev_index, vector<vector<int>>& dp) {
        // Base condition
        if (ind == n)
            return 0;
            
        if (dp[ind][prev_index + 1] != -1)
            return dp[ind][prev_index + 1];
        
        int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
        
        int take = 0;
        if (prev_index == -1 || arr[ind] > arr[prev_index]) {
            take = 1 + getAns(arr, n, ind + 1, ind, dp);
        }
        
        return dp[ind][prev_index + 1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // Create a 2D DP array initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getAns(nums, n, 0, -1, dp);
    }
};


// tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // Create a 2D DP array initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = n - 1; prev >= -1; prev--) {
                int notTake = 0 + dp[i + 1][prev + 1];

                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][prev + 1] = max(notTake, take);
            }
        }
        return dp[0][-1 + 1];
    }
};