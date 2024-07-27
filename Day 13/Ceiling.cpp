// Approach -> Time complexity : O(log(n))

// we are simply using binary search algorithm here to search the ceiling index , because there only we will insert the incoming value .
//     ceiling value : its either equal to the target element , or the smallest value among the elements which are larger than target .

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // create a pointers
        int left = 0, right = nums.size() - 1;

        // traverse the arr
        while (left <= right) {
            // find the mid
            int mid = left + (right - left) / 2;
            // find the answer return index
            if (nums[mid] == target)
                return mid;
            // middle number is greater than the target, so move R to M - 1.
            else if (nums[mid] > target)
                right = mid - 1;
            // middle number is less than the target, so move L to M + 1.
            else
                left = mid + 1;
        }
        // if target is not found then after traversing left pointer must be
        // stood at the index where target should be to maintain sorted order
        return left;
    }
};