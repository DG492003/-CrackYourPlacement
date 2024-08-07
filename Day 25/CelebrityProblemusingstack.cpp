// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int> stk;

        // Step 1: Push all people onto the stack
        for (int i = 0; i < n; ++i)
            stk.push(i);

        // Step 2: Find the potential celebrity
        while (stk.size() > 1) {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();

            if (mat[a][b] == 1)
                // a knows b, so a cannot be a celebrity
                stk.push(b);
            else
                // a does not know b, so b cannot be a celebrity
                stk.push(a);
        }

        // Step 3: Verify the potential celebrity
        int candidate = stk.top();
        for (int i = 0; i < n; ++i) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1; // The candidate knows someone, or someone does not know the candidate
            }
        }

        return candidate;
    }
};