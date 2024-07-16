Approach -> Tc - O(n)
The code starts iterating from i = 1 because we need to compare each element with its previous element to check for duplicates.

The main logic is inside the for loop:
    If the current element nums[i] is not equal to the previous element nums[i - 1], it means we have encountered a new unique element.
    In that case, we update nums[j] with the value of the unique element at nums[i], and then increment move by 1 to mark the next position for a new unique element.
    By doing this, we effectively overwrite any duplicates in the array and only keep the unique elements.
    Once the loop finishes, the value of move represents the length of the resulting array with duplicates removed.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // initialise pointer
        int move = 1;
        // traverse the arr and compare with previous element
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[move] = nums[i];
                move++;
            }
        }
        // return the answer
        return move;
    }
};