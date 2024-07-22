// Approach -> Tc-O(n)

// there is only one pair of i, j such that s(i) != s(j) after the different pair hit, we try removing i or j, the characters in middle should be a palindrome. there is no pair of i, j such that s.(i) != s(j)

class Solution {
private:
    // function to check Palindrome or not after deleting character
    bool check(string s, int i, int j){
        while(i < j)
            if(s[i] != s[j])
                return false;
            else{
                i++;
                j--;
            }
        return true;
    }
public:
    bool validPalindrome(string s) {
        // intialise 2 pointers
        int i = 0,j = s.size()-1;
        // traverse the string
        while(i <= j){
            // check the character equal or not
            if(s[i] != s[j]){
                // in not case we delete one character then again check palindrome or not
                // currently we dont know which character is extra
                // so we either delete from left side or right side then check for Palindrome
                // if anyone is true then return true else return false
                return check(s,i+1,j) || check(s,i,j-1);
            }
            // else update the pointers in case of equal charcters
            else{
                i++;
                j--;
            }
        }
        // no need to delete a character already a palindrome
        return true;
    }
};