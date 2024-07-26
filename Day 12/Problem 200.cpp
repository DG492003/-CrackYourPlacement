// // Problem is similar to Problem 130
// // but here we return the no. of surrounded islands
// // same approach

// TC - > O(n*m)
// SC -> stack space

class Solution {
private:
    // recursive function which checks the O is surrounded or not
    // board - > matrix
    // n,m -> matrix dimensions
    // i,j -> current indexs
    void capture(vector<vector<char>>& board, int n, int m, int i, int j) {
        // check the base condition
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != '1')
            return;
        // else
        // change the '1' into '0'
        board[i][j] = '0';
        // now check all 4 dirctions to check the '1' is surrounded or not
        capture(board, n, m, i + 1, j);
        capture(board, n, m, i - 1, j);
        capture(board, n, m, i, j + 1);
        capture(board, n, m, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // get the board dimensions
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();

        // variable to store the no. of islands
        int numIsland = 0;
        // traverse the grid
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    numIsland++;
                    capture(grid, n, m, i, j);
                }

        return numIsland;
    }
};