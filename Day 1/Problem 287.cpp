// Given TC - O(n) SC - O(1)
// Approach - 
// Assume the array a linked list cycle because one number is repreat;
// Initialize the two pointer - slow and fast
// slow move one step at a time and fast two step at a time 
// as they move in a cycle they will collide
// when collide move fast to index 0 and then move both pointer simulatneously which eventually meet at a duplicate number (Tortoise and hare problem)


class Solution {
public:
    #include <bits/stdc++.h>
    int findDuplicate(vector<int>& nums) {
        // initialise both pointer
        int slow = nums[0];
        int fast = nums[0];
        // Move slow and fast pointers till collision
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // reinitialize the fast pointer
        fast = nums[0];
        // again move both pointer simulatneoulsy till collision
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        // return any pointer bcz collision point is duplicate answer
        return slow;
    }
};