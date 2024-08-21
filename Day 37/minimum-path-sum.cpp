// Time Complexity: O(N*M)
// Reason: At max, there will be N*M calls of recursion.

// Space Complexity: O((M-1)+(N-1)) + O(N*M)
// Reason: We are using a recursion stack space: O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.

class Solution {
private:
    // Helper function to find the minimum sum path from (i, j) to (0, 0) in the
    // matrix
    int minSumPathUtil(int i, int j, vector<vector<int>>& grid,
                       vector<vector<int>>& dp) {
        // Base cases
        // If we are at the top-left corner, the
                                 // minimum path sum is the value at (0, 0)
        if (i == 0 && j == 0)
            return grid[0][0]; 
                                 // If we go out of bounds, return a large value to
                            // avoid considering this path
        if (i < 0 || j < 0)
            return 1000000; 
                            // If the result is already computed, return it

        if (dp[i][j] != -1)
            return dp[i][j]; 
        // Calculate the minimum sum path by considering moving up and moving
        // left
        long left = grid[i][j] + minSumPathUtil(i, j - 1, grid, dp);
        long up = grid[i][j] + minSumPathUtil(i - 1, j, grid, dp);

        // Store the result in the DP table and return it
        return dp[i][j] = min(up, left);
    }

public:
    // Main function to find the minimum sum path in the matrix
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // DP table to memoize results
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // Start from the bottom-right corner
        return minSumPathUtil(n - 1, m - 1, grid, dp);
    }
};