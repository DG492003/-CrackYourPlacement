// Time Complexity: O(n!) due to the exploration of all permutations.
// Space Complexity: O(n) due to the recursion stack and the nums vector.


class Solution {
public:
    void solve(vector<int>& nums, int n, int& ans, int cur_num){
        // base case: if cur_num exceeds n, it means a valid arrangement is found
        if(cur_num >= n+1){
            ans++;
            return;
        }

        // recursive case: try placing cur_num in all possible positions
        for(int j=1; j<=n; j++){
            // check if position j is unoccupied and the divisibility condition is met
            if(nums[j] == 0 && (cur_num % j == 0 || j % cur_num == 0)){
                nums[j] = cur_num;
                solve(nums, n, ans, cur_num+1);
                // backtrack: remove the current number from position j
                nums[j] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> nums(n+1); // create a vector of size n+1 to store the current arrangement
        int ans = 0, ind = 1;
        solve(nums, n, ans, ind); // start solving with the first number
        return ans; // return the total count of valid arrangements
    }
};
