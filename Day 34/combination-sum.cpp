/*
Time Complexity: O(2^t * k) where t is the target, k is the average length
    Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
Space Complexity: O(k*x), k is the average length and x is the no. of combinations





Base Case:
    If the remaining target is 0, add the current combination to ans because it sums to the target.
    If the current index ind reaches the end of the candidates array, stop further exploration.

Recursive Case:
-> Include the current element:
    If the current element (candidates[ind]) is less than or equal to the remaining target, add it to the current combination.
    Call the recursive function with the same index ind and the updated target (target - candidates[ind]).
    After the recursive call, remove the last added element from current to backtrack.
-> Exclude the current element:
    Move to the next element by calling the recursive function with the next index (ind + 1).
*/


class Solution {
public:
    // Helper function to find all combinations that sum up to the target
    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: If we've considered all elements
        if (ind == arr.size()) {
            // If the target is exactly 0, we've found a valid combination
            if (target == 0) {
                // Add the current combination to the answer list
                ans.push_back(ds);
            }
            return;
        }

        // Recursive case 1: Pick the current element

        // Only pick if the current element doesn't exceed the target
        if (arr[ind] <= target) {
            // Include the element in the current combination
            ds.push_back(arr[ind]);
            // Recurse with the same index and updated target
            findCombination(ind, target - arr[ind], arr, ans, ds);
            // Backtrack: remove the last element to explore other possibilities
            ds.pop_back();
        }

        // Recursive case 2: Do not pick the current element
        // Move to the next element in the array
        findCombination(ind + 1, target, arr, ans, ds);
    }

    // Main function to return all unique combinations that sum up to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // To store all valid combinations
        vector<int> ds; // To store the current combination being explored
        // Start the backtracking process from index 0
        findCombination(0, target, candidates, ans, ds);
        return ans; // Return the list of all valid combinations
    }
};
