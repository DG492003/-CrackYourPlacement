// Approach -> Time complexity:O(2^N)  Space complexity: O(n)
// use backtracking
// steps ->
//     -> no. open & close are equal and total size of string formed is 2*n then valid string save it and return
//     -> if open < n i.e, still need to add open bracket
//     -> else if close < open, then add close bracket

class Solution {
private:
    // recusive function
    void solve(string curr, int open, int close, int total, vector<string>& ans){
        // if no. of open parentheses == close parentheses and if string size equal to 2*n
        // save the answer and terminate the recursion bcz we got valid pairs
        if(curr.size() == (2 * total) && open == close){
            ans.push_back(curr);
            return;
        }
        // if open parentheses is less than n, then add open parentheses and update counter
        if(open < total)
            solve(curr + "(", open+1, close, total, ans);
        // else add close parentheses and update counter
        if(close < open)
            solve(curr + ")", open, close+1, total, ans);
    }
public:
    // main function
    vector<string> generateParenthesis(int n) {
        // to store all valid parentheses
        vector<string> ans;
        // call the function
        solve("" ,0, 0, n, ans);
        // return the answer
        return ans;
    }
};