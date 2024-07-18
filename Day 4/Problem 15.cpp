// Approach -> Tc - O(nlogn + n*(n)) Sc - O(no. of triplets)

// to avoid duplicates first sort the array
// traverse the array 
//     kept one number constant and use pointer to find sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // to store the answer
        vector<vector<int>> ans;
        // sort the arr to avoid duplicate triplets
        sort(nums.begin(),nums.end());
        // traverse the arr
        for(int i=0;i<nums.size();i++){
            // to avoid using same number again & again
            if(i>0 && nums[i] == nums[i-1]) continue;
            // initialise 2 pointer 
            int j = i+1, k = nums.size()-1;
            // traverse the subarray
            while(j < k){
                // get the sum
                int sum = nums[i] + nums[j] + nums[k];
                // if sum == target
                if(sum == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    // increment/decrement the pointers
                    j++;k--;
                    // to avoid similiar number & duplicates
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                // if sum > target
                else if (sum > 0)
                    k--;
                // if sum < target
                else
                    j++;
            }
        }
        // return the triplets
        return ans;
    }
};