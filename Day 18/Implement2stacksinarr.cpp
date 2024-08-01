// Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

// twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
// push1 : pushes element into first stack.
// push2 : pushes element into second stack.
// pop1 : pops element from first stack and returns the popped element. If first stack is empty, it return -1.
// pop2 : pops element from second stack and returns the popped element. If second stack is empty, it return -1.

class solution{
  private:
    stack<int> stack1;
    stack<int> stack2;
  public:
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        stack1.push(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        stack2.push(x);
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(stack1.empty())
            return -1;
        int p = stack1.top();
        stack1.pop();
        return p;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(stack2.empty())
            return -1;
        int p = stack2.top();
        stack2.pop();
        return p;
    }
};