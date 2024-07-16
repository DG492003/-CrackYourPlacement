// Approach -> Tc - O(n) Sc - O(n)
// initialise 2 arrs and store the previous result and current el's product from both side
// then just multiply it.

// arr = [10, 3, 5, 6, 2]
// leftarr = [1, 10, 30, 150, 900] fill it from left side by doing this we just skip el from left side
// rightarr = [180, 60, 12, 2, 1] fill it from right side by doing this we just skip el from right side

// prodarr = leftarr * rightarr ==> [180, 600, 360, 300, 900]
// so when we multiply we get product of all els except the current nums[i]


class Solution{
  public:
    #include <bits/stdc++.h>
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //code here 
        
        // construct auxiliary space and answer storing variable
        vector<long long int> leftarr(n,1);
        vector<long long int> rightarr(n,1);
        vector<long long int> prodarr(n,1);
        // now traverse from left and store the product of previous el and current el
        leftarr[0] = 1;
        for(int i=1;i<n;i++)
            leftarr[i] = nums[i-1] * leftarr[i-1];
        //traverse from right and store the product of next el and current el
        rightarr[n-1] = 1;
        for(int i=n-2;i>=0;i--)
            rightarr[i] = nums[i+1] * rightarr[i+1];
        // at last multiply both arr and store the answer
        for(int i=0;i<n;i++)
            prodarr[i] = leftarr[i] * rightarr[i];
        // return the answers
        return prodarr;
    }
};