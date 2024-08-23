// same as longest common substring

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // Length of the first array
        int m = nums2.size(); // Length of the second array

        // Variable to store the maximum length of the common subarray
        int maxi = 0; 

        // Initialize a 2D DP table with (n+1) x (m+1) dimensions
        // dp[i][j] will store the length of the longest common subarray
        // ending at nums1[i-1] and nums2[j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Iterate through each element of nums1 and nums2
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Check if the current elements of both arrays match
                if (nums1[i - 1] == nums2[j - 1]) {
                    // If they match, extend the length of the common subarray
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // Update the maximum length found so far
                    maxi = max(maxi, dp[i][j]);
                } else {
                    // If they do not match, reset the length for this position
                    dp[i][j] = 0;
                }
            }
        }
        // Return the length of the longest common subarray found
        return maxi;
    }
};