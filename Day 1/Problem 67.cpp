// Approach - Tc-> O(max(n,m)) due to reversing
// Initialize variables to store answer and carry
// Initialize n as length of a - 1 and m as length of b - 1
// While n >= 0 or m >= 0 or carry != 0:
//     If n >= 0:
//         carry += integer value of a[n]
//         Decrement n
//     If m >= 0:
//         carry += integer value of b[m]
//         Decrement m
//     Append (carry % 2) as character to ans
//     Update carry to carry // 2

// Reverse ans
// Return ans

class Solution {
public:
    #include <bits/stdc++.h>
    string addBinary(string a, string b) {
        // initialize ans to store ans and carry
        string ans = "";
        int n = a.size()-1, m = b.size()-1;
        int carry = 0;
        // traverse from right side
        while(n >= 0 || m >= 0 || carry){
            // getting elements from a
            if(n >= 0)
                carry += a[n--] - '0';
            // getting elements from b
            if(m >= 0)
                carry += b[m--] - '0';
            // add them and modulus with 2
            ans += carry % 2 + '0';
            // updating carry
            carry /= 2;
        }
        // revserse the answers to make it correct order
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
