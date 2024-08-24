class Solution
{
private:
    // Helper function for recursive calculation with memoization
    int maxSquareSide(vector<vector<char>> &matrix, vector<vector<int>> &memo, int i, int j)
    {
        // Base case: if out of bounds or current cell is '0'
        if (i < 0 || j < 0 || matrix[i][j] == '0')
            return 0;

        // Check if the result is already computed
        if (memo[i][j] != -1)
            return memo[i][j];

        // Recursively find side length of the largest square ending at (i,j)
        int sideLength = min({maxSquareSide(matrix, memo, i - 1, j),
                              maxSquareSide(matrix, memo, i, j - 1),
                              maxSquareSide(matrix, memo, i - 1, j - 1)}) +
                         1;

        // Memoize the result
        memo[i][j] = sideLength;
        return sideLength;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Memoization table initialized with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));

        int maxSide = 0;

        // Compute the maximal square side length for each cell
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    maxSide = max(maxSide, maxSquareSide(matrix, memo, i, j));
                }
            }
        }

        // Return the area of the largest square
        return maxSide * maxSide;
    }
};
