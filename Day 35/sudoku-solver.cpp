// Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
// Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

class Solution {
private:
    // Function to check if placing character 'c' at board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Check if 'c' is already present in the same row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)
                return false;

            // Check if 'c' is already present in the same column
            if (board[i][col] == c)
                return false;

            // Check if 'c' is already present in the 3x3 subgrid
            // Starting row index of the 3x3 subgrid
            int startRow = 3 * (row / 3);
            // Starting column index of the 3x3 subgrid
            int startCol = 3 * (col / 3);

            if (board[startRow + i / 3][startCol + i % 3] == c)
                return false;
        }
        return true;
    }

    // Function to solve the Sudoku puzzle using backtracking
    bool solve(vector<vector<char>>& board) {
        // Iterate through each cell of the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // If the cell is empty (i.e., contains '.')
                if (board[i][j] == '.') {
                    // Try placing digits 1 to 9 in the empty cell
                    for (char c = '1'; c <= '9'; c++) {
                        // Check if placing 'c' in board[i][j] is valid
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place 'c' in the cell

                            // Recursively try to solve the rest of the board
                            if (solve(board))
                                return true; // If successful, return true
                            else
                                board[i][j] = '.'; // Otherwise, backtrack
                        }
                    }
                    // If no valid digit can be placed, return false
                    return false;
                }
            }
        }
        // If no empty cell is found, the board is solved
        return true;
    }
public:
    // main function to solve sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};