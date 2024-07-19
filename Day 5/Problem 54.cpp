// Approach -> Time Complexity: O(m x n) 
// Create and initialize variables 
// top->starting row idx, bottom->ending row idx, left-> starting column idx, and right-> ending idx
// In each outer loop traversal print the elements of a square in a clockwise manner.
//     Print the top row, i.e. Print the elements of the top row from column index left to right and increase the count of the top so that it will move to the next row.
//     Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.
//     Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left and decrease the count of bottom
//     Print the left column, i.e. if left <= right, then print the elements of the left column from the bottom row to the top row and increase the count of left.
//     Run a loop until all the squares of loops are printed.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        // Define ans array to store the result.
        vector<int> ans;
        
        int n = mat.size(); // no. of nows
        int m = mat[0].size(); // no. of columns
        
        // Initialize the pointers for traversal.
        int top = 0, left = 0, bottom = n - 1, right = m - 1;

        // Loop until all elements are not traversed.
        while (top <= bottom && left <= right) {
            
            // For moving left to right
            for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);

            top++;

            // For moving top to bottom.
            for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);

            right--;
            
            // For moving right to left.
            if (top <= bottom) {
            for (int i = right; i >= left; i--)
            ans.push_back(mat[bottom][i]);

            bottom--;
            }

            // For moving bottom to top.
            if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);

            left++;
            }
        }
        return ans;
    }
};
