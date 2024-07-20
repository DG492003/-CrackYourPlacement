// Approach -> Tc - O(N∗M∗Log(N)) - due to sorting and we traverse a only one string which is of size m;

// sort the strings
// then check only first and last string
// if they are same then all have common prefix else noone have

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // first sort the strs
        sort(strs.begin(),strs.end());
        // now we only checks first str and last str bcz if they have same prefix then all have else they dont have any common prefix
        string first = strs[0], last = strs[strs.size()-1];
        // to store ans
        string ans = "";
        // traverse both strs
        for(int i=0;i<min(first.size(),last.size());i++){
            // if at any point mismatch element occurs return answer
            if(first[i] != last[i])
                return ans;
            // else update the answer
            ans += first[i];
        }
        return ans;
    }
};