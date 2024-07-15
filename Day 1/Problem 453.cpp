// Approach- TC - O(nlogn) - sorting SC - O(1)
// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal. In one move, you can increment n - 1 elements of the array by 1.

// step 1 sort the array
// Now if we convert all the elements into smallest numbers it might not be minimum no. of steps same as well as if we convert into largest numbers. For the optimal (minimum) answer we have to choose the median element. (but it changes as per array size i.e, odd or even size)

// step 2 use 2 pointers and move towards each other till collision
// and count/sum the difference of number at that index.

// Like eg 1 3 7 8 11 and suppose we have to convert into integer n
// 1 + x (add x to 1 to make n)
// 11 - y (sub y from 11 to make n)
// 1 + x = 11 - y = n    ===>   11 - 1 = x + y = n (hence we need to find only x & y which is equals to diff of extreme numbers so to convert all we use step2)

class Solution {
public:
    #include <bits/stdc++.h>
    int minMoves(vector<int>& nums) {
        // sort the array
        sort(nums.begin(),nums.end());
        // intialise the moves variable and pointers
        int moves = 0;
        int left = 0, right = nums.size()-1;
        // traverse the arr and count the diff b/w numbers
        while(left <= right)
            moves += abs(nums[left++] - nums[right--]);
        // return the count
        return moves;
    }
};