// Tc - O(n log n)
// Sc - O(n)

class Solution {
public:
    int nthUglyNumber(int n) {
        // Step 1: Define the prime factors for ugly numbers
        vector<int> primes = {2, 3, 5};
        
        // Step 2: Initialize a min-heap to keep track of the smallest ugly numbers
        priority_queue<long, vector<long>, greater<long>> uglyHeap;
        
        // Step 3: Use a set to avoid duplicate entries in the heap
        unordered_set<long> visited;
        
        // Step 4: Start by pushing the first ugly number (1) into the heap
        uglyHeap.push(1);
        
        // Mark 1 as visited
        visited.insert(1);
        long curr; // Variable to store the current ugly number
        
        // Step 5: Extract the smallest ugly number `n` times to get the nth ugly number
        for (int i = 0; i < n; ++i) {
            // Extract the smallest element from the heap
            curr = uglyHeap.top();
            uglyHeap.pop();
            
            // Generate new ugly numbers by multiplying the current ugly number with each prime factor
            for (int prime : primes) {
                long new_ugly = curr * prime;
                
                // If the generated number has not been added to the heap yet, add it
                if (visited.find(new_ugly) == visited.end()) {
                    uglyHeap.push(new_ugly);
                    visited.insert(new_ugly);
                }
            }
        }
        
        // Step 6: The last extracted number is the nth ugly number
        return (int)curr;
    }
};
