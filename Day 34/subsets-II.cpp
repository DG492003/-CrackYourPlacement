class Solution {
private:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result,
                   vector<int>& current) {
        // Add the current subset to the result
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Include the current element
            current.push_back(nums[i]);

            // Recurse with the next element
            backtrack(i + 1, nums, result, current);

            // Backtrack: remove the last element
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result; // To store all unique subsets
        vector<int> current;        // To store the current subset being built

        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        // Start backtracking from index 0
        backtrack(0, nums, result, current);

        return result; // Return all unique subsets
    }
};
