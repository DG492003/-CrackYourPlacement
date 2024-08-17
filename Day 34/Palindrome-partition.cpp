// Time Complexity: O( (2^n) *k*(n/2) )
// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of palindrome list.

// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // To store all the possible palindrome partitions
        vector<vector<string>> res;
        // To store the current partition being explored
        vector<string> path;
        // Start the backtracking process
        partitionHelper(0, s, path, res);
        return res; // Return the list of all valid partitions
    }

private:
    void partitionHelper(int index, string s, vector<string>& path, vector<vector<string>>& res) {
        // Base case: If we have reached the end of the string, add the current
        // partition to the result
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        // Explore all possible partitions starting from the current index
        for (int i = index; i < s.size(); ++i) {
            // Check if the substring from index to i is a palindrome
            if (isPalindrome(s, index, i)) {
                // Add the palindromic substring to the current path
                path.push_back(s.substr(index, i - index + 1));

                // Recur to explore further partitions
                partitionHelper(i + 1, s, path, res);

                // Backtrack: Remove the last added substring from the current
                // path
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        // Check if the substring s[start...end] is a palindrome
        while (start <= end) {
            // If characters don't match, it's not a
            // palindrome
            if (s[start++] != s[end--])
                return false;
        }
        return true; // All characters matched, it's a palindrome
    }
};
