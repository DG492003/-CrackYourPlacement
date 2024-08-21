// Tc == Sc -> O(M∗N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D array to store the number of paths to each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Call the helper function to calculate the number of unique paths
        return dest(dp, m, n, 0, 0);
    }

private:
    // Helper function to calculate the number of unique paths to the
    // bottom-right corner
    int dest(vector<vector<int>>& dp, int m, int n, int i, int j) {
        // If we are out of bounds, return 0 (no path)
        if (i >= m || j >= n)
            return 0;

        // If we have reached the bottom-right corner, return 1 (found a path)
        if (i == m - 1 && j == n - 1)
            return 1;

        // If the number of paths from this cell is already computed, return it
        if (dp[i][j] > 0)
            return dp[i][j];

        // Recursively compute the number of paths by moving right or down
        // Store the result in the current cell to avoid recomputation
        return dp[i][j] = dest(dp, m, n, i + 1, j) + dest(dp, m, n, i, j + 1);
    }
};
