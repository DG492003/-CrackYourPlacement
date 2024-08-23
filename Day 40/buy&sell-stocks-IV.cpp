class Solution {
private:
    int maxUtil(int transNo, int i, vector<int>& prices, int k, vector<vector<int>>& dp) {
        // Base case: if we have completed all transactions or reached the end of the days
        if (i == prices.size() || transNo == 2 * k)
            return 0;

        // If the subproblem is already computed, return the stored result
        if (dp[transNo][i] != -1)
            return dp[transNo][i];

        // Recursive case
        if (transNo % 2 == 0) { // Even transaction number -> Buy state
            dp[transNo][i] = max(-prices[i] + maxUtil(transNo + 1, i + 1, prices, k, dp), 
                                  0 + maxUtil(transNo, i + 1, prices, k, dp));
        } else { // Odd transaction number -> Sell state
            dp[transNo][i] = max(prices[i] + maxUtil(transNo + 1, i + 1, prices, k, dp), 
                                  0 + maxUtil(transNo, i + 1, prices, k, dp));
        }

        return dp[transNo][i];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // Memoization table initialized to -1
        vector<vector<int>> dp(2 * k, vector<int>(n, -1));

        // Start recursion with the first transaction and first day
        return maxUtil(0, 0, prices, k, dp);
    }
};


// tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;

        // dp[transNo][i] will hold the max profit up to day i with exactly
        // transNo transactions
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int transNo = 2 * k - 1; transNo >= 0; transNo--) {
                if (transNo % 2 == 0)
                    // Even transaction number -> Buy state
                    dp[i][transNo] = max(-prices[i] + dp[i+1][transNo+1], dp[i+1][transNo]);
        
                else 
                    // Odd transaction number -> Sell state
                    dp[i][transNo] = max(prices[i] + dp[i+1][transNo+1], dp[i+1][transNo]);
            }
        }

        // The answer is stored in dp[0][0], representing maximum profit from
        // day 0 with 0 transactions
        return dp[0][0];
    }
};

