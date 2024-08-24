class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftP = 1;  // Initialize left product as 1
        int rightP = 1; // Initialize right product as 1
        int ans = nums[0]; // Initialize answer with the first element in the array

        // Iterate through the array
        for(int i = 0; i < n; i++){
            // If leftP or rightP becomes 0, reset them to 1
            leftP = leftP == 0 ? 1 : leftP;
            rightP = rightP == 0 ? 1 : rightP;

            // Update leftP with the product of nums[i]
            leftP *= nums[i];
            // Update rightP with the product of nums[n-i-1]
            rightP *= nums[n-i-1];

            // Update the answer with the maximum of leftP or rightP
            ans = max(ans, max(leftP, rightP));
        }

        return ans; // Return the maximum product found
    }
};
