// Dutch National flag algorithm
// Approach -> Time Complexity: O(N)
// This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:
// arr[0….low-1] contains 0. [Extreme left part]
// arr[low….mid-1] contains 1.
// arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
// The middle part i.e. arr[mid….high] is the unsorted segment.

// Here, as the entire array is unsorted, we have placed the mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.

// run a loop that will continue until mid <= high.
// There can be three different values of mid pointer i.e. arr[mid]
// If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
// If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
// If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
// In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.

class Solution {
public:
    void sortColors(vector<int>& arr) {
        // initialise the pointer
        int left = 0,right = arr.size()-1;
        int mid = 0;
        // traverse the arr
        while(mid<=right){
            // if el is 0 swap left and mid and increment both
            if(arr[mid] == 0)
                swap(arr[left++],arr[mid++]);
            // if el is 1 just increment mid
            else if(arr[mid] == 1)
                mid++;
            // else if el is 2 decrement right but dont move the mid
            else if(arr[mid] == 2)
                swap(arr[right--],arr[mid]);
        }
    }
};