// Approach ->
//     Time Complexity: O(N)
//     Space Complexity: O(N)

// steps ->
//     Take a single queue.
//     push(x): Push the element in the queue.
//         Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
//     pop(): remove the element from the queue.
//     top(): show the element at the top of the queue.
//     size(): size of the current queue.


class MyStack {
private:
    queue<int> Q;

public:
    MyStack() {}

    void push(int x) {
        int s = Q.size();
        Q.push(x);
        for (int i = 0; i < s; i++) {
            Q.push(Q.front());
            Q.pop();
        }
    }

    int pop() {
        int n = Q.front();
        Q.pop();
        return n;
    }

    int top() { return Q.front(); }

    bool empty() { return Q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */