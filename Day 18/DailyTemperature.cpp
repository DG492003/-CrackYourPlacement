// Approach-> TC - O(n) SC - O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // empty stack to keep track of indices.
        stack<int> st;
        // vector to store the number of days until a warmer day for each day's
        // temperature.
        vector<int> DTans(temperatures.size());

        // traverse the arr
        for (int i = 0; i < temperatures.size(); i++) {
            // While the stack is not empty and
            // the current temperature is greater than the temperature at the
            // index on the top of the stack
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                // Update the result for the index at the top of the stack with
                // the difference between the current index and the index on the
                // top of the stack.
                DTans[st.top()] = i - st.top();
                // Pop the index from the stack.
                st.pop();
            }
            // Push the current index onto the stack.
            st.push(i);
        }
        return DTans;
    }
};