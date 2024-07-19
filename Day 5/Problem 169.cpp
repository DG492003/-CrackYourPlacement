// Approach -> TC - O(n) Given Sc must be constant.

// My first approach -> sort the arr and return the middle element because if an element is must present and having n/2 majority then it must be passes through center.

// Second Approach -> Moore's Voting Algorithm
// if element is same occurs, increases the votes/count
// else decreases
// if anytime count == 0 set current element as choosing element which might be a case

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // to store count
        int count = 0;
        // to store majority element
        int majority = nums[0];
        // traversing
        for(int i=0;i<nums.size();i++){
            // if assumed majority element occurs increases the count
            if(majority == nums[i])
                count++;
            // if count = 0 change the majority element
            else if(count == 0)
                majority = nums[i];
            // else just decreases the count
            else
                count--;
        }
        // return the answer
        return majority;
    }
};