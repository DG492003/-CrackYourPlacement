// Approach->  Tc - O(n) Sc->O(1)

class Solution {
private:
    // function to process the strings
    string newStr(string str) {
        // create a new string
        string s = "";
        // traverse the given string
        for (int i = 0; i < str.size(); i++) {
            // if # comes but new string is empty then continue
            if (str[i] == '#' && s.empty())
                continue;
            // if new string is not empty then remove last charcetr
            else if (str[i] == '#' && !s.empty())
                s.pop_back();
            // else just add to it
            else
                s += str[i];
        }
        return s;
    }

public:
    bool backspaceCompare(string s, string t) {
        // first process the string s
        string str1 = newStr(s);
        // process the second string
        string str2 = newStr(t);

        // compare both
        if (str1 == str2)
            return true;
        return false;
    }
};