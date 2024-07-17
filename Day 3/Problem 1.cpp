Approach -> Time Complexity: O(N),
   -> we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
   -> If that element exists, then we will return the current index i.e. i, and the index of the element found using map i.e. mp[target-arr[i]].
   -> If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a hash map
        unordered_map<int, int> mpp;
        // traverse the arr
        for (int i = 0; i < nums.size(); i++) {
            // get the difference between target & current num
            int diff = target - nums[i];
            // if diff is present in map then return pair
            if (mpp.find(diff) != mpp.end()) {
                return {mpp[diff], i};
            }
            // else store the current number with their index
            mpp[nums[i]] = i;
        }
        // return if no pair exists
        return { -1, -1};
    }
};