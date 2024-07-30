// // Approach->
// time complexity:
//     push->O(1)
//     pop->O(1) almost --> amotised
//     top->O(n)
// Space Complexity : O(2N)

// Push ->
// add element in stack1

// Pop ->
// if stack2 isnt empty
//     stack2.pop()
// else    
//     stack1 to stack2 (All elements)
//     stack2.pop()

// Top ->
// if stack2 isnt empty
//     stack2.top()
// else    
//     stack1 to stack2 (All elements)
//     stack2.top()

class MyQueue {
private:
    stack<int> inputSt;
    stack<int> outputSt;

public:
    MyQueue() {}

    void push(int x) { inputSt.push(x); }

    int pop() {
        if (outputSt.empty())
            while (inputSt.size())
                outputSt.push(inputSt.top()), inputSt.pop();

        int x = outputSt.top();
        outputSt.pop();
        return x;
    }

    int peek() {
        if (outputSt.empty())
            while (inputSt.size())
                outputSt.push(inputSt.top()), inputSt.pop();
        return outputSt.top();
    }

    bool empty() { return outputSt.empty() && inputSt.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */