// Approach -> TC - O(n)
// Here we use 2 pointer approach to move all zeroes to the end
// Initialsise 2 pointers left & right
// left used to track the zero and right used to track non-zero

// traverse the arr if nums[right] is nonzero number swap nums[left], nums[right] and increment left pointer
// else move right pointer to next


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // initailise the pointers
        int left = 0;
        // traverse the arr
        for (int right = 0; right < nums.size(); right++)
        // if nonzero number encounter swap and increment left
            if (nums[right] != 0)
                swap(nums[right], nums[left++]);
    }
};