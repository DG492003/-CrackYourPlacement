Approach -> TC-O(N) SC-O(N)

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // arr doesnt have a sufficient no. of nodes to build a tree
        if (!arr.size() || arr.size() < 2)
            return 0;

        int result = 0;
        // using stack to keep a decreasing order by adding smaller values,
        // while there is bigger value
        stack<int> st;

        // traverse the arr
        for (auto n : arr) {
            // if n is bigger than peek(), pop and calculate results
            while (!st.empty() && st.top() <= n) {
                int temp = st.top();
                st.pop();
                if (st.empty())
                    result += temp * n;
                else
                    result += temp * min(st.top(), n);
            }
            // if num is smaller, push into stack
            st.push(n);
        }

        // if there are values left in the stack, they sure will be mutiplied
        // anyway and added to the result.
        // > 1 because we have a peek() after pop() below
        while (st.size() > 1) {
            int topElement = st.top();
            st.pop();
            result += topElement * st.top(); // Multiply with the new top element
        }

        return result;
    }
};