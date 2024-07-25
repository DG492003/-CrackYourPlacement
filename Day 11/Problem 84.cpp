// Approach -> Time Complexity: O(N) + O (N) , Space Complexity: O(N)

// When we traverse the array by finding the next greater element, we found that some elements were inserted into the stack which signifies that after them the smallest element is themselves

// So we can find the area of the rectangle by using arr[i] * (right smaller - left smaller -1 )

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // stack to track next greater element
        stack<int> st;
        // to calculate area
        int maxA = 0;
        // traversing the arr
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            // if st isnt empty & top of stack is greater than curr element
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                // get the top element, pop it
                int height = heights[st.top()];
                st.pop();

                int width;
                // if st is empty set the width equal to curr position
                if (st.empty())
                    width = i;
                // else current position - last greater el - 1
                else
                    width = i - st.top() - 1;
                // get the maxarea
                maxA = max(maxA, width * height);
            }
            // after it push to a stack
            st.push(i);
        }
        // return the maxarea
        return maxA;
    }
};