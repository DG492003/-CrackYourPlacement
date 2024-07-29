// Approach is similar to  aggressive cows & allocation of books

    // -> Have a separate func, which will calculate the total sum of the partitioned subArrays.
    // -> Have a 'mid', as usual in Bin-Search; and the ranges be from the
    //     low ===> Highest Element in the given Array
    //     high ===> Total sum of the Array

class Solution {
private:
    // Give the maximum subarray element or the subarray with the maximum number
    // of elements, must give us the sum which is minimum Hmmm, 
    // largest sum of any subarray is minimized => turns out to be of a pattern that is min of max
    int SubArrayCombSum(vector<int> nums, int maxSum) {
        // This function will return us the number of possible partitions given
        // mid, and the array also having a count of the total sum of each of
        // the subarrays

        int totalSum = 0, partitions = 1;
        // This should be split into 2 parts and, take sum of them
        for (int i = 0; i < nums.size(); i++) {
            if (totalSum + nums[i] > maxSum) {
                // If adding the current element exceeds maxSum, start a new
                // subarray
                partitions++;
                totalSum = nums[i];
            } else {
                // Otherwise, add the current element to the current subarray
                totalSum += nums[i];
            }
        }
        return partitions;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if (k > nums.size())
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = (low + high) / 2;
            int partitions = SubArrayCombSum(nums, mid);
            if (partitions > k) {
                // Here the mid (or the number) we chose was lower, so move
                // towards right and it will give the maximum subarray element
                // or the subarray with the maximum number of elements, must
                // give us the sum which is minimum
                low = mid + 1;
            } else {
                // If not, then move left to get the still lower sum of the
                // maximum elemented subarray
                high = mid;
            }
        }
        return low;
    }
};