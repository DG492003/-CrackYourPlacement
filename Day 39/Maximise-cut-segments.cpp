// memoization
class solution
{
private:
    // Recursive function with memoization to find the maximum number of cuts
    int solve(int n, int x, int y, int z, vector<int> &dp)
    {
        // Base case: If length is negative, it's an invalid state
        if (n < 0)
        {
            return INT_MIN; // Return a very small value to indicate invalid cuts
        }
        // Base case: If length is zero, no more cuts are needed
        else if (n == 0)
        {
            return 0; // Return 0 because no more cuts are needed
        }
        // Return the already computed result if it exists
        else if (dp[n] != -1)
        {
            return dp[n]; // Return the cached result from dp table
        }

        // Recursive cases: Try each possible cut length and find the maximum number of cuts
        int t1 = solve(n - x, x, y, z, dp); // Max cuts with length x cut
        int t2 = solve(n - y, x, y, z, dp); // Max cuts with length y cut
        int t3 = solve(n - z, x, y, z, dp); // Max cuts with length z cut

        // Compute the maximum number of cuts possible
        return dp[n] = 1 + max({t1, t2, t3}); // Take the maximum of the results from the three options
    }

public:
    // Function to initialize the dp table and call the solve function
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);       // Initialize the dp table with -1 (uncalculated states)
        int ans = solve(n, x, y, z, dp); // Call the recursive function to compute max cuts
        return max(ans, 0);              // Ensure the result is non-negative
    }
};


// Tabulation
class solution{
        public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Create a DP table initialized to a very small value
        vector<int> dp(n + 1, INT_MIN);
        
        // Base case: No cuts needed for length 0
        dp[0] = 0;
        
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            int t1 = (i >= x && dp[i - x] != INT_MIN) ? dp[i - x] + 1 : INT_MIN;
            int t2 = (i >= y && dp[i - y] != INT_MIN) ? dp[i - y] + 1 : INT_MIN;
            int t3 = (i >= z && dp[i - z] != INT_MIN) ? dp[i - z] + 1 : INT_MIN;
            
            // The current dp[i] is the maximum of t1, t2, and t3
            dp[i] = max({t1, t2, t3});
        }
        
        // Return the result, ensuring it's non-negative
        return max(dp[n], 0);
    }
};