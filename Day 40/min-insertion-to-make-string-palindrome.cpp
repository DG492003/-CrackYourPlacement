// this question uses same longest palindromic subsequences
// get the longest palindromic subsequence (part which is already palindrome)
// subtarct from size (part which isnot already palindrome)

// if we insert subtarcted part again in revserse order that much insertions we need it

class Solution {
private:
    int longestPalindromeSubseq(string s) {
        // Step 1: Create a reversed version of the string s
        string t = s;
        reverse(t.begin(), t.end());

        // Lengths of the original string and its reversed version
        int n = s.length();
        int m = t.length();

        // Step 2: Initialize a DP table to store the length of the LCS
        // dp[i][j] represents the length of LCS of substrings s[0..i-1] and
        // t[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 3: Fill the DP table using the standard LCS dynamic programming
        // approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, extend the length of the common
                // subsequence
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Otherwise, take the maximum value from either excluding
                    // current character of s or t
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 4: The result is stored in dp[n][m], which represents the length
        // of the longest palindromic subsequence
        return dp[n][m];
    }

public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};