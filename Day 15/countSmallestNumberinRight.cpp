// Approach ->
// Time complexity: O(n log n)
// Space complexity: O(n)

class Solution {
private:
    // Function to find the position where the target should be inserted
    int findPosition(std::vector<int>& temp, int target) {
        int low = 0, high = temp.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (temp[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        // List to store elements in sorted order
        std::vector<int> temp(nums);
        std::sort(temp.begin(), temp.end());

        // List to store the count of smaller elements for each number
        std::vector<int> ans;

        // Traverse through each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // Find the appropriate insertion position for nums[i] in the sorted
            // list
            int pos = findPosition(temp, nums[i]);

            // Remove the number from the sorted list
            temp.erase(temp.begin() + pos);

            // Append the insertion position (which represents the count of
            // smaller elements) to the ans list
            ans.push_back(pos);
        }

        return ans;
    }
};