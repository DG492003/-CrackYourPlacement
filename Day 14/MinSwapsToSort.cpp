// Approach->
// Time Complexity: O(N * Log N) 
// Auxiliary Space: O(N)

// steps->
//     -> Make a new array (called temp), which is the sorted form of the input array. We know that we need to transform the input array to the new array (temp) in the minimum number of swaps. 
//     -> Make a map that stores the elements and their corresponding index, of the input array.
//     So at each i starting from 0 to N in the given array, where N is the size of the array:
//         -> If i is not in its correct position according to the sorted array, then
//         -> We will fill this position with the correct element from the hashmap we built earlier. We know the correct element which should come here is temp[i], so we look up the index of this element from the hashmap. 
//     -> After swapping the required elements, we update the content of the hashmap accordingly, as temp[i] to the ith position, and arr[i] to where temp[i] was earlier
// Return answer

class Solution {
    private:
        void swap(vector<int>& arr, int i, int j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
}
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int swaps = 0;
	    vector<int> temp = nums;
	   // sort the temp
	   sort(temp.begin(),temp.end());
	   // Hashmap which stores the indexes of the input array
       unordered_map<int, int> mpp;
       for(int i=0;i<nums.size();i++)
            mpp[nums[i]] = i;
            
        // traverse the original arr
       for(int i=0;i<nums.size();i++){
            // checking whether the current element is at the right place or not
            if(nums[i] != temp[i]){
                // incrrease swaps count
                swaps++;
                // get the value and swap with element which should come here
                int val = nums[i];
                swap(nums, i, mpp[temp[i]]);
                // Update the indexes in the hashmap accordingly
                mpp[val] = mpp[temp[i]];
                mpp[temp[i]] = i;
            }
       }
       return swaps;
	}
};