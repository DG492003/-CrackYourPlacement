// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
// Space Complexity: O(N)

class Solution {
private:
    // Helper function to solve the N-Queens problem using backtracking
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftrow, vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal, int n) {

        // If all columns are processed, add the board to the answer list
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            // Check if the current position is safe for placing a queen
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {
                // Place the queen on the board
                board[row][col] = 'Q';
                // Mark the row and diagonals as occupied
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recursively solve for the next column
                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

                // Backtrack: Remove the queen and unmark the row and diagonals
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    // Main function to solve the N-Queens problem and return all possible
    // solutions
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Stores all possible solutions
        vector<string> board(n);    // The board configuration
        string s(n, '.');           // A string representing an empty row

        // Initialize the board with empty rows
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        // Vectors to keep track of rows and diagonals where queens are placed
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0),
            lowerDiagonal(2 * n - 1, 0);

        // Start solving from the first column
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

        return ans; // Return all found solutions
    }
};
