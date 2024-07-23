// Problem is also similar to the Print Anagram together
// Approach -> Time complexity: O(n∗k)   Space complexity: O(n∗k) (K is the length of the longest string)

// steps ->
// get hashkey of every string
// add all strings having same hash key

// hashkey --> 'tea' have key like "a1e1t1" alphabetically arranged letters with their frquency


class Solution {
private:
    // function to generate the frquency string
    string getfrq(string str){
        // arr to store the characters with frquency
        vector<int> count(26, 0);
        // get frequency of all character
        for(char ch: str)
            count[ch - 'a']++;
        
        // initialise the empty string
        string frq = "";
        // traverse the arr
        for(int i=0;i<26;i++)
            // if arr[i] isnt empty then add charcter with count to string
            if(count[i] != 0){
                frq += (char)('a' + i);
                frq += to_string(count[i]);
            }
        // return the frquency string (like a1e1t1)
        return frq;
    }

public:
    // main function
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // if given list is empty return null/ empty list of strings
        if(strs.size() == 0)
            return {{""}};

        // // else
        // // create a map which store frequency as a key and vectors to store anagrams
        unordered_map<string, vector<string>> frqstr;
        // create a vector of string vector to store the ans
        vector<vector<string>> result;

        // traverse the list of strings and add frqstring as a key similar frqstrings as a values
        // eg - a1e1t1 -> {tea,eat,ate}
        for(auto str: strs)
            // call the function to fetch key and store values, similar key's values added to same vector
            frqstr[getfrq(str)].push_back(str);

        // now traverse the map to store the result
        for(auto lst: frqstr)
            result.push_back(lst.second);

        // return the result
        return result;        
    }
};
