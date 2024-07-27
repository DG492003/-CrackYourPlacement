// Sorting the array: Arrays.sort(arr); sorts the array in O(n log⁡ n).
// Two-pointer approach:
//     We maintain two pointers i and j. Initially, i is set to 0 and j is set to 1.
//     We then loop through the array while both i and j are within the bounds of the array.
//     We calculate the difference diff = arr[j] - arr[i].
//     If diff matches the given x and i is not equal to j, we return 1 indicating a pair is found.
//     If diff is less than x, we need a larger difference, so we increment j.
//     If diff is greater than x, we need a smaller difference, so we increment i.
// This approach ensures that we efficiently check for the required pair in O(n log⁡ n) time due to sorting and linear traversal.

class solution{
      public:
    int findPair(int n, int x, vector<int> &arr) {
        // sort the arr
        sort(arr.begin(),arr.end());
        // intiialise pointers
        int left = 0, right = 1;
        // traverse the arr
        while(left <= right && right < n){
            // get the difference between pair
            int val = arr[right] - arr[left];
            // check if diff = x and number is not same then return 1
            if(val == x && left != right)
                return 1;
            // If diff is greater than x, we need a smaller difference, so we increment left
            else if(val > x)
                left++;
            // If diff is less than x, we need a larger difference, so we increment right
            else
                right++;
        }
        return -1;
    }
};