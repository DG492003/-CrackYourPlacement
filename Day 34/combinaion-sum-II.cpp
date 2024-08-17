// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

// Space Complexity:O(k*x)

// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.


class Solution {
private:
    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: If the target is 0, we've found a valid combination
        if (target == 0) {
            // Add the current combination to the results
            ans.push_back(ds); 
            return;
        }

        // Iterate through the array starting from the current index
        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates: if the current element is the same as the
            // previous one, skip it
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            // If the current element is greater than the remaining target, no
            // point in continuing (pruning)
            if (arr[i] > target)
                break;

            // Include the current element in the combination
            ds.push_back(arr[i]);

            // Recur with the next index and the updated target
            findCombination(i + 1, target - arr[i], arr, ans, ds);

            // Backtrack: remove the last added element before moving to the
            // next
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to handle duplicates and make pruning effective
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans; // To store all unique combinations
        vector<int> ds;          // To store the current combination being built

        // Start the backtracking process from index 0
        findCombination(0, target, candidates, ans, ds);

        return ans; // Return the list of all valid combinations
    }
};