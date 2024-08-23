class solution{
private:
    // Helper function to backtrack and find all LCS sequences
    void solve(int i, int j, string s, string t, string temp, vector<vector<int>>& dp, set<string>& lcs, unordered_map<string, bool>& vis) {
        // Base case: if we've reached the beginning of either string
        if (i == 0 || j == 0) {
            reverse(temp.begin(), temp.end()); // Reverse the LCS string before adding it
            lcs.insert(temp); // Add the LCS string to the set
            return;
        }

        // Generate a unique key for the current state to avoid revisiting
        string key = to_string(i) + to_string(j) + temp;
        if (vis.find(key) != vis.end()) {
            return; // If this state is already visited, return
        }
        vis[key] = true; // Mark this state as visited

        // If characters match, add the character to the current LCS and move diagonally
        if (s[i - 1] == t[j - 1]) {
            temp += s[i - 1];
            solve(i - 1, j - 1, s, t, temp, dp, lcs, vis);
        } else {
            // If characters don't match, move left or up depending on the DP table values
            if (dp[i - 1][j] == dp[i][j]) {
                solve(i - 1, j, s, t, temp, dp, lcs, vis);
            }
            if (dp[i][j - 1] == dp[i][j]) {
                solve(i, j - 1, s, t, temp, dp, lcs, vis);
            }
        }
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Fill the DP table using the standard LCS dynamic programming approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Backtrack to find all LCS sequences
        set<string> lcs;
        int lcslen = dp[n][m]; // Length of the LCS

        // Iterate through the DP table to start backtracking from points that have the LCS length
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dp[i][j] == lcslen) {
                    unordered_map<string, bool> vis;
                    solve(i, j, s, t, "", dp, lcs, vis);
                }
            }
        }

        // Step 3: Convert the set of unique LCS sequences to a vector to return
        vector<string> res(lcs.begin(), lcs.end());
        return res;
    }
};