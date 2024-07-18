// Approach -> Tc-O(n) and constant space
// We modify the array here

// Steps->
// hop to index which associated to the number.
// convert into negative 
// if number already negative store it and return

// arr = [1, 1, 2]
// find nums[abs(nums[i]) - 1] ==> nums[abs(1) - 1] => [-1, 1, 2] (due to 0-based indexing we use -1)
// again for next steps get 1 again and when we process we find it already negative so store it and return

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // to store duplicates
        vector<int> Duplicate;
        // traverse the arr
        for(int i=0;i<nums.size();i++){
            // if number at index is less than zero means its a duplicate
            if(nums[abs(nums[i]) - 1] < 0)  
                Duplicate.push_back(abs(nums[i]));
            // else convert number into negative
            nums[abs(nums[i]) - 1] *= -1;
        }
        // return all duplicates
        return Duplicate;
    }
};