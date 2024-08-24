// memoization
class Solution
{
private:
    // Recursive function with memoization to find the maximum number of strings
    // that can be formed with given 'm' zeroes and 'n' ones
    int memoFindMax(vector<pair<int, int>> &strs, int i, int m, int n,
                    vector<vector<vector<int>>> &dp)
    {
        // Base case: if the index i is out of bounds, return 0
        if (i >= strs.size())
            return 0;

        // If the result is already computed and stored in dp array, return it
        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        // Extract the number of zeroes and ones from the current pair
        int zeroes = strs[i].first;
        int ones = strs[i].second;
        // Initialize variables for including or excluding the current pair
        int include = 0, exclude = 0;

        // Check if including the current pair is possible
        if (m - zeroes >= 0 && n - ones >= 0)
        {
            // Include the current pair and recursively solve for the next index
            // with updated m and n
            include = 1 + memoFindMax(strs, i + 1, m - zeroes, n - ones, dp);
        }

        // Exclude the current pair and recursively solve for the next index
        // with the same m and n
        exclude = memoFindMax(strs, i + 1, m, n, dp);

        // Store the result in the dp array for future reference
        // Return the maximum value obtained by either including or excluding
        // the current pair
        return dp[i][m][n] = max(include, exclude);
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // Initialize a 3D dp array with dimensions [strs.size()+1][m+1][n+1],
        // initialized to 0
        vector<vector<vector<int>>> dp(
            strs.size() + 1,
            vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        // Vector to store the pairs of {zeros, ones} for each string in strs
        vector<pair<int, int>> str1;

        // Loop through each string in strs to count zeroes and ones
        for (auto s : strs)
        {
            int ones = 0, zeros = 0;
            for (auto ch : s)
            {
                if (ch == '1')
                    ones++;
                if (ch == '0')
                    zeros++;
            }
            str1.push_back({zeros, ones});
        }

        // Call the memoized recursive function starting from the first string
        return memoFindMax(str1, 0, m, n, dp);
    }
};
