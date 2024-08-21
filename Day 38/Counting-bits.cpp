// memoization
class Solution {
private:
    vector<int> memo;

    int bitscount(int id) {
        if (id == 0 || id == 1)
            return id;

        // Check if result is already computed
        if (memo[id] != -1)
            return memo[id];

        // Compute the result and store it in the memoization table
        memo[id] = (id & 1) + bitscount(id >> 1);
        return memo[id];
    }

public:
    vector<int> countBits(int n) {
        memo = vector<int>(n + 1, -1);  // Initialize memoization table
        vector<int> co;
        for (int i = 0; i <= n; i++) {
            co.push_back(bitscount(i));
        }
        return co;
    }
};



// Tabulation
class Solution {
public:
    vector<int> countBits(int n) {
        // Create a dp vector of size n+1 initialized with -1
        vector<int> dp(n + 1, -1);
        for (int i = 0; i <= n; i++) {
            // Base cases: dp[0] = 0 and dp[1] = 1
            if (i < 2)
                dp[i] = i;
            // i & 1 gives the least significant bit (either 0 or 1)
            // dp[i >> 1] gives the count of 1-bits in the number i / 2
            else
                dp[i] = (i & 1) + dp[i >> 1];
        }
        // Return the vector containing the count of 1-bits for all numbers from
        // 0 to n
        return dp;
    }
};
