// Approach -> TC - O(log(Columnnumber))
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// step1 : observe Pattern
// step2 : start from getting Modulus of n-1 by 26 (n-1 bcz to deal with 0-based indexing)
//         getting corresponding character
//         Now contuing the above steps till n>0 by dividing n-1 by 26

class Solution {
public:
    #include <bits/stdc++.h>
    string convertToTitle(int columnNumber) {
        // initialise the variable to store result
        string ans = "";
        // Getting Modulus of 26 again & again till it becomes 0
        while(columnNumber > 0){
            char rem = ((columnNumber - 1) % 26) + 'A'; // Getting corresponding char
            ans = rem + ans; // append the char in beginning
            columnNumber = (columnNumber - 1) / 26; // divide the number to continue process
        }
        // return the answer
        return ans;
    }
};