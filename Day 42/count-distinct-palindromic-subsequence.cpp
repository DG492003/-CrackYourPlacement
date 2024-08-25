class Solution
{
public:
    const int MOD = 1e9 + 7;
    int countPalindromicSubsequences(const string &s)
    {
        int n = s.size();
        // Initialize the DP table with -1 (indicating uncomputed values)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, dp);
    }

private:
    int helper(const string &S, int start, int end, vector<vector<int>> &dp)
    {
        // Base case: if the start index is greater than the end index
        if (start > end)
            return 0;

        // Base case: if there's only one character (a single-character string
        // is always a palindrome)
        if (start == end)
            return 1;

        // Check if the result for this subproblem is already computed
        if (dp[start][end] != -1)
            return dp[start][end];

        int res = 0;
        // If the characters at start and end are the same
        if (S[start] == S[end])
        {
            int left = start + 1;
            int right = end - 1;

            // Move left pointer to the right until we find a character equal to
            // S[start]
            while (left <= right && S[left] != S[start])
            {
                left++;
            }
            // Move right pointer to the left until we find a character equal to
            // S[end]
            while (left <= right && S[right] != S[end])
            {
                right--;
            }

            // Case: There are two duplicates of the end characters (start and
            // end)
            if (left < right)
                // Add subsequences where start and end are included, minus
                // those already counted in the middle
                res += 2 * helper(S, start + 1, end - 1, dp) - helper(S, left + 1, right - 1, dp);

            // Case: There is one duplicate of the end characters (start and
            // end)
            else if (left == right)
                // Add subsequences where start and end are included, plus one
                // for the single character in the middle
                res += 2 * helper(S, start + 1, end - 1, dp) + 1;

            // Case: No duplicates of the end characters
            else
                // Add subsequences where start and end are included, plus two
                // for the two new single characters
                res += 2 * helper(S, start + 1, end - 1, dp) + 2;
        }

        else
            // Case: Characters at start and end are different
            // Count subsequences by excluding the start character and the end
            // character, and adjust for overcounting
            res += helper(S, start + 1, end, dp) +
                   helper(S, start, end - 1, dp) -
                   helper(S, start + 1, end - 1, dp);
        // Store the result in dp table and return it
        // Ensure the result is non-negative and modulo 1000000007
        return dp[start][end] = res < 0 ? res + MOD : res % MOD;
    }
};
