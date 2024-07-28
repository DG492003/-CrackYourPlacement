// it is totally similar to Allocate Books Problem
// but there is distributed max no. of pages to min students thats why we return low
// here we minimum distance between any two of them is the maximum possible thats why we return high
// Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))

// Algorithm:
//     -> First, we will sort the given stalls[] array.
//     -> Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 1 and the high will point to (stalls[n-1]-stalls[0]). As the ‘stalls[]’ is sorted, ‘stalls[n-1]’ refers to the maximum, and ‘stalls[0]’ is the minimum element.
//     -> Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
//     -> Eliminate the halves based on the boolean value returned by canWePlace():
//     We will pass the potential distance, represented by the variable 'mid', to the ‘canWePlace()' function. This function will return true if it is possible to place all the cows with a minimum distance of ‘mid’.
//         -> If the returned value is true: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the maximum number. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
//         -> Otherwise, the value mid is greater than the distance we want. This means the numbers greater than ‘mid’ should not be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
//     Finally, outside the loop, we will return the value of high as the pointer will be pointing to the answer.

class Solution {
private:
    bool canWePlace(vector<int> &stalls,int n, int dist, int cows) {
        int cntCows = 1; //no. of cows placed
        int last = stalls[0]; //position of last placed cow.
        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                cntCows++; //place next cow.
                last = stalls[i]; //update the last location.
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        //sort the stalls[]:
        sort(stalls.begin(), stalls.end());
    
        int low = 1, high = stalls[n - 1] - stalls[0];
        //apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWePlace(stalls, n ,mid, k) == true) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};