// Overall Complexity: O(k * C(n, k)) for both time and space.


class Solution {
private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // Base case: If the current combination has k numbers, add it to the
        // result
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Explore further by adding numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            // Include i in the current combination
            current.push_back(i);

            // Recurse to add further numbers
            backtrack(i + 1, n, k, current, result);

            // Exclude i from the current combination (backtrack)
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result; // To store all combinations
        vector<int> current; // To store the current combination being explored

        // Start backtracking from the first number (1)
        backtrack(1, n, k, current, result);

        return result; // Return all the generated combinations
    }
};
