// Approach -> Tc - O(n)

// As we see number of substrings of size needle length is length of haystack minus length of needle+1.
// so using two pointer we just used a for loop till (length of haystack-length of needle)
// then checked if the character in needle is equal to character of haystack. 
//     If its equal we just kept on incrementing j. 
//     If the j is equal to needle length then we found our first substring that is equal to needle and we return the index of first character of that substring. 
//     If we dont find the substring in the haystack then we simply return -1.

class Solution {
public:
    int strStr(string haystack, string needle) {
        // get the size of the both of the strings
        int n = haystack.size();
        int m = needle.size();
        // check the special case
        if(n < m)
            return -1;
        // traverse over the possible substrings 
        for(int i=0;i<=n-m;i++){
            // initialize the pointer to traverse the second string
            int j = 0;
            // if element matches check the whole string
            while(j<m && haystack[i+j] == needle[j])
                j++;
            // at some point j equals to size second string return idx
            if(j == m)
                return i;
        }
        // else return the -1
        return -1;
    }
};