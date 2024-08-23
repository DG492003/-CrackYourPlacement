// Memoization
class Solution
{
private:
    // Utility function to determine if a subset with the given sum exists
    bool partitionUtil(int i, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        // Base case: if sum becomes zero, a subset is found
        if (sum == 0)
            return true;

        // Base case: if at the first element, check if it equals the sum
        if (i == 0)
            return nums[i] == sum;

        // If the subproblem has already been solved, return the stored result
        if (dp[i][sum] != -1)
            return dp[i][sum];

        // Recursive call to not include the current element
        bool notpick = partitionUtil(i - 1, sum, nums, dp);

        // Recursive call to include the current element, only if it's less than
        // or equal to the remaining sum
        bool pick = false;
        if (nums[i] <= sum)
            pick = partitionUtil(i - 1, sum - nums[i], nums, dp);

        // Store and return the result of the current subproblem
        return dp[i][sum] = notpick || pick;
    }

public:
    // Function to check if the array can be partitioned into two subsets with
    // equal sum
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();

        // Calculate the total sum of the array
        for (auto i : nums)
            sum += i;

        // If the sum is odd, it's not possible to partition it into two equal
        // subsets
        if (sum % 2 == 1)
            return false;

        else
        {
            // Initialize a 2D dp array with -1 (indicating uncalculated states)
            vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

            // Use the utility function to check for subset with sum equal to
            // half of the total sum
            return partitionUtil(n - 1, sum / 2, nums, dp);
        }
    }
};

// Tabulation
class Solution{
public:
    int equalPartition(int N, int arr[]) {
        int sum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < N; i++)
            sum += arr[i];

        // If the sum is odd, it's not possible to partition it into two equal subsets
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;

        // Create a 2D dp array where dp[i][j] represents if a subset with sum j can be formed using the first i elements
        vector<vector<bool>> dp(N, vector<bool>(target + 1, false));

        // Base case: A subset with sum 0 is always possible (by selecting no elements)
        for (int i = 0; i < N; i++) {
            dp[i][0] = true;
        }

        // Base case: For the first element, only the subset with sum equal to arr[0] is possible
        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        // Fill the dp table
        for (int i = 1; i <N; i++) {
            for (int j = 1; j <= target; j++) {
                // Not picking the current element
                bool notpick = dp[i - 1][j];

                // Picking the current element (if it's less than or equal to the current sum)
                bool pick = false;
                if (arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];

                // Store the result in dp table
                dp[i][j] = notpick || pick;
            }
        }

        // The result will be in the last cell, indicating if a subset with sum equal to target is possible
        return dp[N - 1][target];
    }
};