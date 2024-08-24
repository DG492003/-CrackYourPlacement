// memoization
class solution
{
private:
    // Define the possible moves from each digit
    vector<vector<int>> neighbors = {
        {0, 8},          // 0 can move to 0, 8
        {1, 2, 4},       // 1 can move to 1, 2, 4
        {2, 1, 3, 5},    // 2 can move to 2, 1, 3, 5
        {3, 2, 6},       // 3 can move to 3, 2, 6
        {4, 1, 5, 7},    // 4 can move to 4, 1, 5, 7
        {5, 2, 4, 6, 8}, // 5 can move to 5, 2, 4, 6, 8
        {6, 3, 5, 9},    // 6 can move to 6, 3, 5, 9
        {7, 4, 8},       // 7 can move to 7, 4, 8
        {8, 5, 7, 9, 0}, // 8 can move to 8, 5, 7, 9, 0
        {9, 6, 8}        // 9 can move to 9, 6, 8
    };

    // Memoization function
    int countSequencesHelper(int n, int digit, vector<vector<int>> &memo)
    {
        if (n == 1)
        {
            return 1;
        }

        if (memo[n][digit] != -1)
        {
            return memo[n][digit];
        }

        int result = 0;
        for (int neighbor : neighbors[digit])
        {
            result += countSequencesHelper(n - 1, neighbor, memo);
        }

        memo[n][digit] = result;
        return result;
    }

public:
    long long getCount(int n)
    {
        // Your code goes here
        if (n == 1)
            return 10; // Each digit can stand alone as a sequence

        // Initialize memoization table
        vector<vector<int>> memo(n + 1, vector<int>(10, -1));

        int totalSequences = 0;
        for (int digit = 0; digit <= 9; ++digit)
        {
            totalSequences += countSequencesHelper(n, digit, memo);
        }

        return totalSequences;
    }
};

// tabulation
class solution
{
private:
    // Define the possible moves from each digit
    vector<vector<int>> neighbors = {
        {0, 8},          // 0 can move to 0, 8
        {1, 2, 4},       // 1 can move to 1, 2, 4
        {2, 1, 3, 5},    // 2 can move to 2, 1, 3, 5
        {3, 2, 6},       // 3 can move to 3, 2, 6
        {4, 1, 5, 7},    // 4 can move to 4, 1, 5, 7
        {5, 2, 4, 6, 8}, // 5 can move to 5, 2, 4, 6, 8
        {6, 3, 5, 9},    // 6 can move to 6, 3, 5, 9
        {7, 4, 8},       // 7 can move to 7, 4, 8
        {8, 5, 7, 9, 0}, // 8 can move to 8, 5, 7, 9, 0
        {9, 6, 8}        // 9 can move to 9, 6, 8
    };

public:
    long long getCount(int n)
    {
        if (n == 1)
        {
            return 10; // Each digit can stand alone as a sequence
        }

        // Initialize DP table
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

        // Base case: Length 1 sequences
        for (int digit = 0; digit <= 9; ++digit)
        {
            dp[1][digit] = 1;
        }

        // Fill DP table
        for (int len = 2; len <= n; ++len)
        {
            for (int digit = 0; digit <= 9; ++digit)
            {
                dp[len][digit] = 0;
                for (int neighbor : neighbors[digit])
                {
                    dp[len][digit] += dp[len - 1][neighbor];
                }
            }
        }

        // Sum up all sequences of length n
        long long totalSequences = 0;
        for (int digit = 0; digit <= 9; ++digit)
        {
            totalSequences += dp[n][digit];
        }

        return totalSequences;
    }
};