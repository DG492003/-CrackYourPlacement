// Approach -> Tc - O(n) Sc - O(n)
// -> Start with an initial prefix sum of 0.
// -> As you go through each number in the array, update the prefix sum by adding the current number.
// -> Calculate the remainder of this prefix sum when divided by ( k ).
// -> Use the hash map to check if this remainder has been seen before:
//         If it has, it means there are subarrays that sum to a multiple of ( k ), and you increase your count by how many times this remainder has been seen.
//         Update the hash map to include this new remainder.

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // create a map to store a remainder 
        unordered_map<int, int> map;
        // To handle subarrays that start from the beginning
        map[0] = 1;
        // to store sum of subarray
        int prefix_sum = 0;
        // to store count of subarrays
        int count = 0;
        // traverse the arr
        for (int i = 0; i < nums.size(); i++) {
            // Update prefix sum
            prefix_sum += nums[i];
            //  Calculate the remainder of the prefix sum divided by k
            int remainder = prefix_sum % k;
            // Adjust negative remainders to be positive
            if (remainder < 0)
                remainder += k;
            // If this remainder has been seen before, it means there are subarrays ending here that are divisible by k
            if (map.find(remainder) != map.end()) {
                // increment the count of subarrays
                count += map[remainder];
                // also increase the frequency
                map[remainder]++;
            }
            // else store the remainder with their frequency 
            else {
                map[remainder] = 1;
            }
        }
        // return the count of subarrays
        return count;
    }
};