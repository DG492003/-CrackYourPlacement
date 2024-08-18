class Solution {
public:
    string findMaximumNum(string s, int k) {
        string maxNum = s;  // Initialize the maximum number with the given string
        backtrack(s, 0, k, maxNum);
        return maxNum;
    }

private:
    void backtrack(string &s, int index, int k, string &maxNum) {
        if (k == 0 || index >= s.size()) {
            return;
        }

        // Find the maximum digit from the current index to the end
        char maxDigit = *max_element(s.begin() + index, s.end());

        // If the current digit is already the largest possible, no need to swap
        if (s[index] == maxDigit) {
            backtrack(s, index + 1, k, maxNum);
            return;
        }

        // Try swapping the current digit with all occurrences of the max digit
        for (int i = s.size() - 1; i > index; --i) {
            if (s[i] == maxDigit) {
                // Swap the digits
                swap(s[index], s[i]);

                // Update the maximum number found
                maxNum = max(maxNum, s);

                // Recursively call backtrack with one less swap
                backtrack(s, index + 1, k - 1, maxNum);

                // Backtrack (swap back)
                swap(s[index], s[i]);
            }
        }
    }
};