// Approach -> TimeComplexity: O(n) SpaceComplexity: O(n)

// steps->
    // create a stack
    // traverse the string
    // get the characters, ch
    // if ch is digit form a number
    // if a sign -> + push the num
    // if a sign -> - push the -num
    // if a sign -> * get the num perform operation then push
    // if a sign -> / get the num perform operation then push
    // ignore the spaces 
    // if ch is a sign then update the sign

class Solution {
public:
    int calculate(string s) {
        // create a stack to track the operations
        stack<int> st;
        // variable to track the sign by default make it positive bcz no sign
        // means a positive number
        char sign = '+';
        // traverse the string
        for (int i = 0; i < s.size(); i++) {
            // get the character
            char ch = s[i];

            // check if ch is digit or not
            if (isdigit(ch)) {
                // if yes then get the whole number
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }

                // decrease the counter i bcz above while condition increases i
                // first then check for it
                i--;

                // check for a sign
                // if sign is '+' then pushed to stack
                if (sign == '+')
                    st.push(num);

                // if sign is '-' then pushed negative of num
                else if (sign == '-')
                    st.push(-1 * num);

                // if sign is '* or /' then get the above element perform
                // opeartion then push
                else if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (sign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
            }

            // now if ch is not a digit then it may be a sign or a space
            // we want to ignore space so we just update the sign
            else if (ch != ' ')
                sign = ch;
        }

        // at last add all the elements of the stack
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};