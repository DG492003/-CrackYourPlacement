class Solution
{
private:
    const int MOD = 1e9 + 7;

    // Define the valid moves from each digit
    unordered_map<int, vector<int>> moves = {
        {0, {4, 6}}, {1, {6, 8}}, {2, {7, 9}}, {3, {4, 8}}, {4, {0, 3, 9}}, {5, {}}, {6, {0, 1, 7}}, {7, {2, 6}}, {8, {1, 3}}, {9, {2, 4}}};

    // Memoization function
    int countWays(int num, int steps, vector<vector<int>> &dp)
    {
        // Base case: If steps left is 1, return 1 (single digit is a valid number)
        if (steps == 1)
            return 1;

        // If result is already computed, return it
        if (dp[num][steps] != -1)
            return dp[num][steps];

        int totalWays = 0;

        // Calculate the number of ways from each possible move
        for (int move : moves[num])
        {
            totalWays = (totalWays + countWays(move, steps - 1, dp)) % MOD;
        }

        // Store the result in dp array and return it
        return dp[num][steps] = totalWays;
    }

public:
    int knightDialer(int n)
    {
        // Initialize memoization table with -1 (indicating uncomputed state)
        vector<vector<int>> dp(10, vector<int>(n + 1, -1));

        int result = 0;

        // Start from each digit and count the total number of sequences of length n
        for (int i = 0; i <= 9; i++)
        {
            result = (result + countWays(i, n, dp)) % MOD;
        }

        return result;
    }
};