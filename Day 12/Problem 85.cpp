// Approach -> TC - O(n2) SC - O(n)

// This Problem use Largest Rectangle area problem as it is
// we just traverse the each row and check the largest rectangle area
// after that we update the row by adding 1 if mat[i][j] is 1 else nothing and check again the area

class Solution {
private:
    // uses largest rectangle in a histogram code as it is
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // maintain a row arr and get the first row in it
        vector<int> rowArr(matrix[0].size(), 0);

        int maxArea = INT_MIN;

        // traverse the matrix
        for (int i = 0; i < matrix.size(); i++) {
            // update the row
            // if val is 1 then add else convert into 0
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1')
                    rowArr[j]++;
                else
                    rowArr[j] = 0;
            }
            // after updating row call the largest area
            maxArea = max(maxArea, largestRectangleArea(rowArr));
        }
        return maxArea;
    }
};