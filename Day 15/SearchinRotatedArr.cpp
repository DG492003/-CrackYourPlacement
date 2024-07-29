// Approach -> O(logn)

// steps->
//     Place the 2 pointers i.e. low and high
//     Calculate the ‘mid’
//     Check if arr[mid] = target: If it is, return True.
//     Check if arr[low] = arr[mid] = arr[high]:
//         if this condition is satisfied, we will just increment the low pointer and decrement the high pointer by one step. We will not perform the later steps until this condition is no longer satisfied. So, we will continue to the next iteration from this step.
//     If arr[low] <= arr[mid]: This condition ensures that the left part is sorted.
//         If arr[low] <= target && target <= arr[mid]: It signifies that the target is in this sorted half. So, we will eliminate the right half (high = mid-1).
//         Otherwise, the target does not exist in the sorted half. So, we will eliminate this left half by doing low = mid+1.
//     Otherwise, if the right half is sorted:
//         If arr[mid] <= target && target <= arr[high]: It signifies that the target is in this sorted right half. So, we will eliminate the left half (low = mid+1).
//         Otherwise, the target does not exist in this sorted half. So, we will eliminate this right half by doing high = mid-1.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // size of the numsay.
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // if mid points the target
            if (nums[mid] == target)
                return mid;

            // Edge case:
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // if left part is sorted:
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    // element exists:
                    high = mid - 1;
                } else {
                    // element does not exist:
                    low = mid + 1;
                }
            } else { // if right part is sorted:
                if (nums[mid] <= target && target <= nums[high]) {
                    // element exists:
                    low = mid + 1;
                } else {
                    // element does not exist:
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};