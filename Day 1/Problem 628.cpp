// Approach -> Tc- O(n)
// Due to the fact -ve * -ve = +ve 
// we have to comapare the
// max1 * max2 * max3 and min1 * min2 * max1 

class Solution {
public:
    #include <bits/stdc++.h>
    int maximumProduct(vector<int>& nums) {
        // initialize max variables
        int max1 = INT_MIN;
        int max2 = max1;
        int max3 = max1;
        // initialize min variables 
        int min1 = INT_MAX;
        int min2 = min1;

        // Traverse the array,gets the value
        for(int i=0;i<nums.size();i++){
            int el = nums[i];
            // max check
            if (el > max1){
                max3 = max2;
                max2 = max1;
                max1 = el;
            } else if (el > max2){
                max3 = max2;
                max2 = el;
            } else if (el > max3)
                max3 = el;

            // min check
            if(el < min1){
                min2 = min1;
                min1 = el;
            } else if(el < min2)
                min2 = el;
        }

        // return the answer by comparing
        return max((min1 * min2 * max1), (max1 * max2 * max3));      
    }
};