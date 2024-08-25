class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;

        // Arrays to store the maximum height to the left and right of each bar
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);

        // Fill the left_max array
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // Fill the right_max array
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // Calculate the total amount of water trapped
        int waterTrapped = 0;
        for (int i = 0; i < n; ++i) {
            waterTrapped += min(left_max[i], right_max[i]) - height[i];
        }

        return waterTrapped;
    }
};