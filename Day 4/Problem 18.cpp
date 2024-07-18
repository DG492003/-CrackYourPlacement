// Approach -> 
// Time Complexity: O(N3), where N = size of the array. 
// Space Complexity: O(no. of quadruplets)

// Way to solve the Problem similar to 3-sum(problem 15)

class Solution {
public:
    // approach similar to 3-sum problem
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //size of the array
        int n = nums.size(); 
        vector<vector<int>> ans;
        // sort the given array:
        sort(nums.begin(), nums.end());
        //calculating the quadruplets:
        for (int i = 0; i < n; i++) {
            // avoid the duplicates while moving i:
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                // avoid the duplicates while moving j:
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                // 2 pointers:
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    // to avoid overflow
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    // checks
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++; l--;
                        //skip the duplicates:
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < target) k++;
                    else l--;
                }
            }
        }
        // return the quadruplets
        return ans;
    }
};
