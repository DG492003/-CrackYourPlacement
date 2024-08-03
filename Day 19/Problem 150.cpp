// similar to evaluation of Postfix expressions

class Solution {
private:
    int operate(int a, int b, string ch) {
        if (ch == "+")
            return a + b;
        else if (ch == "-")
            return b - a;
        else if (ch == "*")
            return a * b;
        else
            return b / a;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            // if curr element is arth opeartor
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                // take out last 2 number
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                // perform opeartions
                int res = operate(op1, op2, tokens[i]);

                // store into stack
                st.push(res);
            } else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};