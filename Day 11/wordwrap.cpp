// Word Wrap

class Solution {
private:
    // its an array which stores the values to avoid the same computataion
    // this method also known as memoization
    vector<vector<int>> dp;
    // function to wraps the words in a line
        // curr -> current word
        // spaces -> no. of space already used
        // nums -> given arr
        // k -> maxwidth of a line
    int wrap(int curr,int spaces,vector<int>&nums,int &k){
        // if we have at last word then dont count spaces
        if(curr == nums.size())
            return 0;
            
        // check the vector if current word and spaces already used or not
        if(dp[curr][spaces] != -1)
            return dp[curr][spaces];
            
        // ok now we have 2 option either way we continue to same line
        // or jump on next line
        
        // first check for same line
        int sameLine = INT_MAX;
        // newspaces = already used space + gap b/w word + word length
        int newSpaces = spaces + 1 + nums[curr];
        // if this less than k then check for next word
        if(newSpaces <= k)
            sameLine = wrap(curr+1, newSpaces, nums, k);
        
        
        // else we check for next line
        // if we add word on next line then current word is next total space occupied == wordlenght
        // and also add extra spaces we add by squaring
        int nextLine = wrap(curr+1, nums[curr], nums, k) + (k - spaces) * (k - spaces);
        
        // at last just store the answer in vector dp by comapring both
        // hence we want only minimise solution
        return dp[curr][spaces] = min(sameLine, nextLine);
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        // initialise the dp vector by -1
        dp.resize(n+1, vector<int>(k+1, -1));
        // call the function we start with 1 bcz we dont want to add space without starting the word
        return wrap(1, nums[0], nums, k);
    } 
};