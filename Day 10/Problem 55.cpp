// Approach -> Tc - O(n)
// goal -> to reach last index
// how to solve?
//     suppose we stand on a last index and we want to reach first index is similar to go from first to last index
//     thats why we start from last index 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // stand on a last index
        int goal = nums.size() - 1;

        // traverse from the last
        // we choose n-2 bcz if we stand on a last idx which means we already on
        // a goal node
        for (int i = nums.size() - 2; i >= 0; i--)
            // if nums[i](no. of steps) + i(position) >= goal idx i.e., it can
            // be possible to jump to goal idx from ith idx so we update goal
            // idx to i bcz we reach ith idx we can reach last idx
            if (i + nums[i] >= goal)
                goal = i;

        // so we reach at 0th idx thats mean we can reach last idx anyway else noway        
        return goal == 0 ? true : false;
    }
};