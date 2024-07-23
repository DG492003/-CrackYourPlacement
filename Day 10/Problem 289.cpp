// Approach -> TC - O(mn) SC - O(mn)

// we make a clone of a board
// and get the live neighbours of each idx from a clone board
// check the conditions 
// update the board

// hence we get the live neighbours based on a clone board so chnges on a current board cant effect the results

class Solution {
private:
    int get_liveneighbour(vector<vector<int>>& board, int i, int j, int m,
                          int n) {
        int live = 0;
        // check the upper neighbours
        if (i > 0 && board[i - 1][j] == 1)
            live++;
        // check the lower neighbours
        if (i < m - 1 && board[i + 1][j] == 1)
            live++;
        // check the left neighbour
        if (j > 0 && board[i][j - 1] == 1)
            live++;
        // check the right neighbour
        if (j < n - 1 && board[i][j + 1] == 1)
            live++;
        // check for upper diagonal
        if (i > 0 && j > 0 && board[i - 1][j - 1])
            live++;
        // check for bottom diagonal
        if (i > 0 && j < n - 1 && board[i - 1][j + 1] == 1)
            live++;
        // check for left diagonal
        if (i < m - 1 && j > 0 && board[i + 1][j - 1] == 1)
            live++;
        // check for right diagonal
        if (i < m - 1 && j < n - 1 && board[i + 1][j + 1] == 1)
            live++;

        return live;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        // create a another board to track changes
        vector<vector<int>> curr = board;
        // get the dimensions
        int m = board.size();
        int n = board[0].size();
        // traverse the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // get the lively neighbours
                int live = get_liveneighbour(curr, i, j, m, n);

                // if current cell is dead but it has 3 live neighbours it also
                // alive
                if (board[i][j] == 0 && live == 3)
                    board[i][j] = 1;
                // if current cell is alive
                // if live neighbours are greater than 3 or less than 2 either
                // way cell died
                else if (board[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = 0;
            }
        }
    }
};