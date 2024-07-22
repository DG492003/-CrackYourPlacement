// Approach -> Time Complexity: O(N), Space Complexity: O(1)

// -> Add a space to s to ensure the last word is processed.
// -> Create empty strings ans (for the final result) and t (to accumulate each word).
// -> Iterate through each character in s.
//     On encountering a space, prepend t to ans if t is non-empty and reset t.
//     If not a space, add the character to t.
//     Return ans without the trailing space.

class Solution {
public:
    string reverseWords(string s) {
        // add extra space to string to process last word
        s += " ";
        // strings to store answer & words
        string ans = "",t = "";
        // traverse the string
        for(int i=0;i<s.size();i++){
            // if ch is space
            if(s[i] == ' '){
                // check the word is empty or not
                // if it is append word then add space to the answer 
                if(t != "")
                    ans=t+" "+ans;
                // change word back to empty
                t = "";
            }
            // if ch is not a space then just add the charcter in a word
            else
                t += s[i];
        }

        // return the answer by removing trailing space
        return ans.substr(0,ans.size()-1);
    }
};