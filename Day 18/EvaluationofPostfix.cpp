// Approach-> TC - O(n) SC - O(N)


class solution{
    private:
        int operate(int a, int b, char ch){
            if(ch == '+')   return a+b;
            if(ch == '-')   return b-a;
            if(ch == '*')   return a*b;
            if(ch == '/')   return b/a;
        }
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<S.size();i++){
            // if curr element is arth opeartor
            if(S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/'){
                // take out last 2 number
                int op1 = st.top();st.pop();
                int op2 = st.top();st.pop();
                
                // perform opeartions
                int res = operate(op1,op2,S[i]);
                
                // store into stack
                st.push(res);
            }
            else if(S[i]>='0' and S[i]<='9')
               st.push(S[i]-'0');
        }
        return st.top();
    }
};