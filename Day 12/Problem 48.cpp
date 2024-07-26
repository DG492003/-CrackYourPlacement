// By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

// Approach:
//     Time Complexity: O(N*N) + O(N*N) for transposing and reversing.
//     Space Complexity: O(1).

// Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
// Step 2: Reverse each row of the matrix.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        // reverse the each row
        for (auto& row : matrix)
            reverse(row.begin(), row.end());
    }
};