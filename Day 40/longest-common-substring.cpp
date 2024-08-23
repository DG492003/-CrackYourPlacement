// this question uses same approach as LCS
// i use tabulation method with slight change
// as we only find common substring so if characters dont matches i set to 0

class solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        int maxi = 0;

        // Initialize a 2D DP table with (n+1) x (m+1) dimensions
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Iterate through each character of both strings
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // If characters match, increment the length of common substring
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0; // Reset if characters do not match
                }
            }
        }
        return maxi; // Return the length of the longest common substring
    }
};