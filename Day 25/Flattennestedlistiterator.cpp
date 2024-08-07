// Time Complexity:
//     NestedIterator constructor: O(N)
//     next function: O(1)
//     hasNext function: O(1)
// Space Complexity:
//     O(N) for the queue storing all integers.
//     O(D) for the recursive call stack depth (usually much smaller than N).

// Implement the NestedIterator class:
    // NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
    // int next() Returns the next integer in the nested list.
    // boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    // Queue to hold all integers in a flattened form
    queue<int> q;

public:
    // Constructor to initialize the iterator with a nested list
    NestedIterator(vector<NestedInteger>& nestedList) {
        unravel(nestedList); // Flatten the nested list into the queue
    }

    // Helper function to recursively flatten the nested list
    void unravel(const vector<NestedInteger>& nestedList) {
        for (const auto& nested : nestedList) {
            if (nested.isInteger()) {
                // If the element is an integer, push it to the queue
                q.push(nested.getInteger());
            } else {
                // If the element is a list, recursively flatten it
                unravel(nested.getList());
            }
        }
    }

    // Return the next integer in the flattened form
    int next() {
        int x = q.front(); // Get the front element of the queue
        q.pop();           // Remove the front element from the queue
        return x;          // Return the integer
    }

    // Check if there are more integers to be returned
    bool hasNext() {
        return !q.empty(); // Return true if the queue is not empty
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */