// Approach -> Tc - O(n*m*4^(k)) n,m - matrix dimension, k - size of word
// as we have 4 calls(side) in a 1 recursive call

// just travrse the matrix if one first ch of word found then search in all 4 dircetions
// before searching modify the element so that it cant be revisited and after search change to a orginal element

class Solution {
private:
    // recursive function to search the word
    // board -> matrix
    // word -> to be search
    // i,j -> index of word[0]
    // n,m -> dimensions of matrix
    // k -> track the word
    bool search(vector<vector<char>>& board, string word, int i, int j, int n,
                int m, int k) {
        // if k is equal to word length means word found
        if (k == word.size())
            return true;
        // check for boundary cases and if character is not same
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
            return false;

        // to avoid revisting we mark the character by # sign
        board[i][j] = '#';
        // search on all 4 directions
        bool left = search(board, word, i + 1, j, n, m, k + 1);
        bool right = search(board, word, i - 1, j, n, m, k + 1);
        bool top = search(board, word, i, j - 1, n, m, k + 1);
        bool bottom = search(board, word, i, j + 1, n, m, k + 1);

        // after checking re-modify the character
        board[i][j] = word[k];

        // if in any direction we found a word then we return true
        return left || right || top || bottom;
    }

public:
    // main function
    bool exist(vector<vector<char>>& board, string word) {
        // traverse the matrix
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // if word[0] is found then we call a recursive function
                if (board[i][j] == word[0])
                    // if function returns true then we find a word
                    if (search(board, word, i, j, board.size(), board[0].size(),
                               0))
                        return true;
            }
        }
        // else we dont find the word
        return false;
    }
};