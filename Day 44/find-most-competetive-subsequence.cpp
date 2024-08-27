class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // Initialize an empty stack to keep track of the most competitive
        // subsequence
        vector<int> stack;

        // Loop through each element in the input array nums
        for (int i = 0; i < nums.size(); ++i) {

            // While the stack is not empty, the top element of the stack is
            // greater than the current element nums[i], and there are enough
            // remaining elements in nums (including the current element) to
            // fill the stack to size k, pop the top element from the stack.
            while (!stack.empty() && stack.back() > nums[i] && stack.size() - 1 + nums.size() - i >= k)
                stack.pop_back();

            // If the current size of the stack is less than k, push the current
            // element nums[i] onto the stack
            if (stack.size() < k)
                stack.push_back(nums[i]);
        }

        // Return the stack, which now contains the most competitive subsequence
        // of length k
        return stack;
    }
};