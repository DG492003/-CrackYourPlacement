// Approach -> Tc-O(n)
// take 2 pointers from very ends
// get height & breadth 
// get area
// find maximum
// move pointer whose height is short

class Solution {
public:
    int maxArea(vector<int>& height) {
        // initailise 2 pointers from each end
        int left = 0, right = height.size()-1;
        // to store max volume
        int maxVolume = INT_MIN;
        // iterate in the arr
        while(left <= right){
            // get the height 
            int L = min(height[left],height[right]);
            // get the breadth
            int B = right - left;
            // find max area
            maxVolume = max(maxVolume, L * B);
            // increment/decrement the pointer whose height is short
            if(height[left] < height[right])
                left++;
            else right--;
        }
        // return the volume
        return maxVolume;
    }
};