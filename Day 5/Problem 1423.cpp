// Approach -> TC - O(k)

// Step-1: Firstly calculate the sum of First K Elements
// Step-2: Then for last K elements, we will do it by removing one element one by one from First K elements and including elements one by one from last.
// Step-3: Take Two Pointers:
//     Left Index on - k-1th Index
//     Right Index on - n-1th Index
// Step-4: Now we will do 3 steps simultaneously in every iteration :
//     Decrease the size from Window of 1st Kth Elements
//     Increase the size in the window of Last Kth Elements
//     Check if the current total sum is greater than the maxSum. If YES, then update the maxSum.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // * Firstly, figure out the sum of 1st Kth elements
        int leftSum = 0, rightSum = 0, maxSum = 0;
        for(int i = 0; i < k; i++) 
            leftSum += cardPoints[i];
        // * Initially, out maxSum becomes left Sum
        maxSum = leftSum;

        // removing one element one by one from First K elements and including elements one by one from last.
        for(int leftIdx = k-1, rightIdx = n-1; leftIdx >= 0; leftIdx--, rightIdx--){
            // * Shrink from START (leftIdx)
            leftSum -= cardPoints[leftIdx];
            //  * Increase size from END (rightIdx)
            rightSum += cardPoints[rightIdx];
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};