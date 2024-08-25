class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int totalCount = 0;

        // Initialize the first row
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        // Initialize the first column
        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else 
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }

        // Calculate the total number of squares
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalCount += dp[i][j];
            }
        }

        return totalCount;
    }
};