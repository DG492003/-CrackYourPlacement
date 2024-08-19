class Solution {
public:
    int climbStairs(int n) {
        // Base cases: If there are 0 or 1 steps, there is only 1 way to climb
        // the stairs
        if (n == 0 || n == 1) {
            return 1;
        }

        // Create a vector to store the number of ways to reach each step
        vector<int> dp(n + 1);

        // There is 1 way to reach step 0 and step 1
        dp[0] = dp[1] = 1;

        // Calculate the number of ways to reach each step from 2 to n
        for (int i = 2; i <= n; i++) {
            // The number of ways to reach step i is the sum of the ways to
            // reach steps i-1 and i-2
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The result is the number of ways to reach the nth step
        return dp[n];
    }
};
