// Approach -> O(n*m)

// here we found the 'O' which are unsurrounded by the "X" and present at the border
// mark with another character
// then convert all 'O' into 'X' bcz they all consider as surrounded
// and reverse the step 2

class Solution {
private:
    // recursive function which checks the O is surrounded or not
    // board - > matrix
    // n,m -> matrix dimensions
    // i,j -> current indexs
    void capture(vector<vector<char>>& board, int n, int m, int i, int j) {
        // check the base condition
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != 'O')
            return;
        // else
        // change the 'O' into '-'
        board[i][j] = '-';
        // now check all 4 dirctions to check the 'O' is surrounded or not
        capture(board, n, m, i + 1, j);
        capture(board, n, m, i - 1, j);
        capture(board, n, m, i, j + 1);
        capture(board, n, m, i, j - 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        // get the board dimensions
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();

        // traverse the board
        // if O occurs checks it is surrounded or not only if it is present on
        // border Traverse the board and mark unsurrounded 'O' starting from the
        // borders
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                capture(board, n, m, i, 0);
            if (board[i][m - 1] == 'O')
                capture(board, n, m, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                capture(board, n, m, 0, j);
            if (board[n - 1][j] == 'O')
                capture(board, n, m, n - 1, j);
        }

        // now we have all unsurrounded regions so convert all O into X
        // now at last changes all the '-' into back to 'O'
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '-')
                    board[i][j] = 'O';
            }
    }
};