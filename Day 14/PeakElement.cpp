// If arr[i] > arr[i-1]: we are in the left half.
// If arr[i] > arr[i+1]: we are in the right half.

// Check if arr[mid] is the peak element:
//     -> If arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the peak element. We will return the index ‘mid’.
//     -> If arr[mid] > arr[mid-1]: This means we are in the left half and we should eliminate it as our peak element appears on the right. So, we will do this:
//     low = mid+1.
//     -> Otherwise, we are in the right half and we should eliminate it as our peak element appears on the left. So, we will do this: high = mid-1. This case also handles the case for the index ‘mid’ being a common point of a decreasing and increasing sequence. It will consider the left peak and eliminate the right peak.

// time Complexity: O(log n)

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        // Edge cases:
        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        // inittialise the pointers to traverse the arr
        int left = 0, right = arr.size() - 2;
        while (left <= right) {
            // find the mid
            int mid = left + (right - left) / 2;

            // check the condition(strictly greater than a neighbor)
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return mid;
            else if (arr[mid] > arr[mid + 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};