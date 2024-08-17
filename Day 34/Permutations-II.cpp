// TC - O(n!*n) also SC

class Solution {
private:
    void backtrack(int start, vector<int>& nums, set<vector<int>>& result) {
        // Base case: if we have reached the end of the array, add permutation
        // to result
        if (start == nums.size()) {
            result.insert(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates: If the current element is the same as the
            // previous one
            if (i > start && nums[i] == nums[start])
                continue;

            // Swap the current element with the element at the start position
            swap(nums[i], nums[start]);

            // Recurse with the next start position
            backtrack(start + 1, nums, result);

            // Swap back to restore the array to its original state
            swap(nums[i], nums[start]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result; // Use a set to store unique permutations
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        backtrack(0, nums, result);     // Start backtracking
        return vector<vector<int>>(result.begin(), result.end()); // Convert set to vector
    }
};
