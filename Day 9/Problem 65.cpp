// Approach -> TC - O(n) Sc - O(1)
// Rules are given, code are self explainatory

class Solution {
public:
    bool isNumber(string s) {
        // initailise the 3 boolean variables
        bool isnum = false, isE = false, isDot = false;
        // a varibale which counts the no. of plus & minus
        int count = 0;

        // traverse the string
        for (int i = 0; i < s.size(); i++) {
            // get the current character
            char ch = s[i];

            // check for digit
            if (isdigit(ch))
                isnum = true;

            // check for +/-
            else if (ch == '+' || ch == '-') {
                // if operators occurs more than 1 return false;
                if (count >= 2)
                    return false;

                // also if operators occurs in between the strings and previous
                // character isnt the e/E then also return false
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;

                // also if they occur at last then also not a valid number
                if (i == s.size() - 1)
                    return false;

                // else just increase counter
                count++;
            }

            // check for dot
            else if (ch == '.') {
                // check if "e/E" or "." already comes before then return false
                if (isE || isDot)
                    return false;
                // also if only . occurs without digit then also not a valid
                // number
                if (i == s.length() - 1 && !isnum)
                    return false;

                // else just update dot boolean
                isDot = true;
            }

            // check for e/E
            else if (ch == 'e' || ch == 'E') {
                // if e alredy occurs or number is not occurs or e is last
                // character then return false
                if (isE || !isnum || i == s.length() - 1)
                    return false;
                // else just update bool
                isE = true;
            }

            // if another things other than above occurs return false;
            else
                return false;
        }

        // all cases passes hence a valid number
        return true;
    }
};