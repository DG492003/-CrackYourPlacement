// Approach -> Tc - O(n) Sc - O(n)
// using stack;

class Solution {
public:
    bool isValid(string s) {
        // create an empty stack to store opening brackets
        stack<char> st;
        // loop through each character in the string
        for (char c : s) { 
            // if the character is an opening bracket so push it onto the stack
            if (c == '(' || c == '{' || c == '[')  
                st.push(c); 
            // if the character is a closing bracket
            else { 
                // if the stack is empty or the closing bracket doesn't match the corresponding opening bracket at the top of the stack, the string is not valid, so return false
                if (st.empty() || 
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; 
                }
                // otherwise, pop the opening bracket from the stack
                st.pop(); 
            }
        }
        // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets, so the string is valid, otherwise, there are unmatched opening brackets, so return false
        return st.empty(); 
    }
};