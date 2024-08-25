class Solution {
private:
    // Recursive function to find the minimum number of attempts required
    int solve(int k, int n, vector<vector<int>>& memo) {
        // Base case: No floors to test
        if (n == 0)
            return 0;
        // Base case: Only one egg left, need to try all floors sequentially
        if (k == 1)
            return n;
        // Return the memoized result if it already exists
        if (memo[k][n] != -1)
            return memo[k][n];

        int low = 1, high = n;
        int result = INT_MAX;

        // Use binary search to find the optimal floor to drop the egg from
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Compute the number of moves if the egg breaks
            int breakCase = solve(k - 1, mid - 1, memo);
            // Compute the number of moves if the egg does not break
            int noBreakCase = solve(k, n - mid, memo);

            // The worst-case scenario for this drop is the maximum of the two
            // outcomes plus one drop
            int worstCase = 1 + max(breakCase, noBreakCase);

            // Update the result with the minimum number of moves found
            result = min(result, worstCase);

            // Binary search optimization: Adjust the search range based on the
            // outcomes
            if (breakCase < noBreakCase) {
                low =
                    mid + 1; // If breaking case is less, move to higher floors
            } else {
                high = mid -
                       1; // If no breaking case is less, move to lower floors
            }
        }

        // Memoize and return the result for the current subproblem
        memo[k][n] = result;
        return result;
    }

public:
    // Main function to find the minimum number of moves for k eggs and n floors
    int superEggDrop(int k, int n) {
        // Initialize the memoization table with -1 (indicating uncomputed
        // states)
        vector<vector<int>> memo(k + 1, vector<int>(n + 1, -1));
        // Call the recursive function to compute the result
        return solve(k, n, memo);
    }
};