/*
TC - O(n)

Initialization:
    left and right vectors store the indices of previous and next smaller elements, respectively.
    ans vector stores the results, initialized with zeros.

Compute Previous Smaller Elements:
    Iterate over the array.
    Use a stack to find the previous smaller element for each element and store it in the left vector.

Compute Next Smaller Elements:
    Iterate over the array from the end.
    Use a stack to find the next smaller element for each element and store it in the right vector.

Compute Maximum of Minimums:
    Iterate over the array.
    Calculate the length of the window where the current element is the minimum.
    Update the ans vector with the maximum value for each window length.

Fill Remaining Entries:
    Ensure that each entry in the ans vector contains the maximum value for window sizes greater than or equal to its index.

Final Adjustment:
    Remove the first element from ans as it is unused (index 0). */

class Solution{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n){
        stack<int> st;
        // Vectors to store the previous and next smaller elements for each element
        vector<int> left(n, -1), right(n, n);
        // Vector to store the result, initialized with zeros
        vector<int> ans(n + 1, 0);
    
        // Fill left array with indices of previous smaller elements
        for (int i = 0; i < n; i++) {
            // Pop elements from stack while stack is not empty and top of stack is greater than or equal to arr[i]
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            // If stack is not empty, then top of stack is the previous smaller element
            if (!st.empty()) left[i] = st.top();
            // Push current index to stack
            st.push(i);
        }
    
        // Clear the stack to reuse for right array computation
        while (!st.empty()) st.pop();
    
        // Fill right array with indices of next smaller elements
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack while stack is not empty and top of stack is greater than or equal to arr[i]
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            // If stack is not empty, then top of stack is the next smaller element
            if (!st.empty()) right[i] = st.top();
            // Push current index to stack
            st.push(i);
        }
    
        // Fill the answer array with maximum of minimums for every possible length
        for (int i = 0; i < n; i++) {
            // Length of the window where arr[i] is the minimum
            int len = right[i] - left[i] - 1;
            // Update the result array with the maximum value of minimums
            ans[len] = max(ans[len], arr[i]);
        }
    
        // Fill the rest of the result array
        for (int i = n - 1; i >= 1; i--) {
            // Ensure that ans[i] contains the maximum value for window sizes >= i
            ans[i] = max(ans[i], ans[i + 1]);
        }
    
        // Remove the first element as it's unused (index 0)
        ans.erase(ans.begin());
    
        // Return the result
        return ans;
    }
};