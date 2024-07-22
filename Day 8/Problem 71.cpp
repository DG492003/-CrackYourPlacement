// Approach -> TC - O(n) Sc - O(n)

// -> Create a Stack of String with following condition.
// -> Iterate the loop till you doesn't reaches the end of string.
//     -> If you encounter a "/" then ignore it.
//     -> Create a temp String & Iterate the while loop till you doesn't find "/" and append it to temp.
//     -> Now check if temp == "." , then ignore it.
//     -> If temp == ".." then pop the element from the stack if it exists.
//     -> If no of the above 2 matches push temp to stack as you find a valid path.
//     -> Check out temp string on basis of above conditions till you doesn't find "/".
// -> Now add all stack elements to result as res = "/" + st.top() + res
// -> If res.size() is 0 then return "/" if no directory or file is present.
// -> At last return res.

class Solution {
public:
    string simplifyPath(string path) {
        // stack to track directory
        stack<string> st;
        // string to store result
        string res;
        // traverse the arr
        for(int i=0;i<path.size();i++){
            // if "/" encounters ignore it
            if(path[i] == '/')
                continue;
            // create a temporary string to store data between "/"
            string temp;
            while(i<path.size() && path[i] != '/')
                temp += path[i++];
            
            // if temp have "."i.e, no change so ignore it
            if(temp == ".")
                continue;
            
            // if temp have ".." i.e, move one directory up pop the stack if not empty
            else if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }
            
            // else just add data into stack
            else
                st.push(temp);
        }

        // traverse the stack and convert into path format
        while(!st.empty()){
            // add "/" first then top of the stack
            res = "/" + st.top() + res;
            // after adding pop the stack
            st.pop();
        }

        // if final path is empty just return "/";
        if(res.size() == 0)
            return "/";

        // else return tha final path
        return res;
    }
};