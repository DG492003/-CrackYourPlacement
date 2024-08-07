/*
Time complexity: O(n)
Space complexity: O(n)

To arrive at the solution, we must track two things for each element arr[i]:
    left[i]: the index of the first smaller element to the left of arr[i]
    right[i]: the index of the first element that is less than or equal to arr[i] to the right

With left[i] and right[i] determined,no. of subarrays in which arr[i] is the minimum = (i-left[i])*(right[i]-i). */


using ll = long long;    // Define a shorthand for long long
const int MOD = 1e9 + 7; // Define the modulus value for the problem

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size(); // Get the length of the input array
        // Vector to store the idx of previous smaller element for each el
        vector<int> left(length, -1);
        // Vector to store the idx of next smaller element for each el
        vector<int> right(length, length);
        // Stack to help in finding the previous and next smaller el
        stack<int> stk;

        // Find previous smaller elements
        for (int i = 0; i < length; ++i) {
            // while the stack is not empty and the top element of the stack is
            // greater than or equal to the current element, pop elements from
            // the stack
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            // if the stack is not empty, set left[i] to the index of the top
            // element of stack
            if (!stk.empty())
                left[i] = stk.top();
            // push the current index i onto the stack.
            stk.push(i);
        }

        // Reset the stack to reuse it for finding next smaller elements
        stk = stack<int>();

        // Find next smaller elements
        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i])
                stk.pop();
            if (!stk.empty())
                right[i] = stk.top();
            stk.push(i);
        }

        // Variable to store the sum of minimums of all subarrays
        ll sum = 0; 

        // Calculate the sum of minimums of all subarrays
        for (int i = 0; i < length; ++i) {
            // Number of subarrays in which nums[i] is the minimum element
            // (i - left[i]) gives the number of subarrays ending at i
            // (right[i] - i) gives the number of subarrays starting at i
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD; // Ensure the sum stays within the modulus
        }
        
         // Return the result
        return sum;
    }
};
