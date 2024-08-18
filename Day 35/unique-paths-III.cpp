// Time Complexity: O((m * n)!) due to exploring all possible permutations of visiting the cells.
// Space Complexity: O(m * n) due to the recursion stack and the grid storage.

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startX, startY, endX, endY, emptyCount = 0;

        // Find the start and end points and count the number of non-obstacle cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                } else if (grid[i][j] == 0) {
                    ++emptyCount;
                }
            }
        }

        // Start DFS from the start point
        return dfs(grid, startX, startY, endX, endY, emptyCount);
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int endX, int endY, int emptyCount) {
        // Check if out of bounds or the cell is an obstacle or already visited
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1 || grid[x][y] == -2) {
            return 0;
        }

        // Check if we reached the end point
        if (x == endX && y == endY) {
            return emptyCount == -1 ? 1 : 0;
        }

        // Mark the current cell as visited
        int temp = grid[x][y];
        grid[x][y] = -2; // -2 indicates the cell is visited

        // Explore all 4 directions
        int paths = 0;
        paths += dfs(grid, x + 1, y, endX, endY, emptyCount - 1);
        paths += dfs(grid, x - 1, y, endX, endY, emptyCount - 1);
        paths += dfs(grid, x, y + 1, endX, endY, emptyCount - 1);
        paths += dfs(grid, x, y - 1, endX, endY, emptyCount - 1);

        // Unmark the current cell (backtracking)
        grid[x][y] = temp;

        return paths;
    }
};
