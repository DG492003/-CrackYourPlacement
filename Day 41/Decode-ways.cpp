class Solution
{
public:
    int numDecodingsTopDown(string s, int index, vector<int> &memo)
    {
        // Base case: if we've reached the end of the string, return 1
        if (index == s.length())
        {
            return 1;
        }

        // If the string starts with '0', it can't be decoded
        if (s[index] == '0')
        {
            return 0;
        }

        // If we've already calculated this subproblem, return the cached result
        if (memo[index] != -1)
        {
            return memo[index];
        }

        // Decode using a single character
        int ways = numDecodingsTopDown(s, index + 1, memo);

        // Decode using two characters if valid
        if (index + 1 < s.length() &&
            (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
        {
            ways += numDecodingsTopDown(s, index + 2, memo);
        }

        // Store the result in memo
        return memo[index] = ways;
    }

public:
    int numDecodings(string s)
    {
        vector<int> memo(s.length(), -1);
        return numDecodingsTopDown(s, 0, memo);
    }
};
