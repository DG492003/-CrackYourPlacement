// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n)

class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);

        // Explore further by including each remaining element one by one
        for (int i = start; i < nums.size(); i++) {
            // Include nums[i] in the current subset
            current.push_back(nums[i]);

            // Recurse to add further elements
            backtrack(i + 1, nums, current, result);

            // Exclude nums[i] from the current subset (backtrack)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; // To store all subsets
        vector<int> current; // To store the current subset being explored

        // Start backtracking from the first index
        backtrack(0, nums, current, result);

        return result; // Return all the generated subsets
    }
};
