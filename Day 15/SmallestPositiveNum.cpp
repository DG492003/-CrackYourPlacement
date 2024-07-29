// we can sort easily and then just to find but optimise way is below.
// Approach ->
// Time Complexity: O(N), Traversing the array of size N.
// Auxiliary Space: O(1)

// steps ->
//     -> Initialize a variable mx to the minimum integer value (INT_MIN).
//     -> Iterate through the array arr using a for loop.
//         If the current element arr[i] is less than or equal to 0, set it to 0.
//         Update the maximum value mx by taking the maximum of mx and arr[i].
//     -> Increment mx by 1.
//     -> Iterate through the array arr again.
//         If the current element arr[i] is greater than 0:
//             Calculate the index ind as (arr[i] % mx) - 1.
//             If ind is a valid index within the array bounds, update arr[ind] by adding mx to it.
//     -> Iterate through the array arr once more.
//         If the current element arr[i] < max, return i + 1 else  no missing number is found, return n + 1.

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) { 
        // Your code here
        int maxi = INT_MIN;
        // convert -ve numbers into 0 and get the max element
        for(int i=0;i<n;i++) {
            if(arr[i]<=0)
                arr[i]=0;
            maxi=max(maxi,arr[i]);
        }
        // increment by 1 to get size of the arr having all positives number
        maxi += 1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                // get the idx as per 0-bsed indexing
                int idx = arr[i] % maxi -1;
                // check the idx if its within range add maxi on it
                if(idx<n && idx>=0)
                    arr[idx] += maxi;
            }
        }
        
        // check the element which is not incremented 
        // because its index is not present in arr
        for(int i=0;i<n;i++)
            if(arr[i]<maxi)
                return i+1;
                
        // else return size + 1 
        return n+1;
    } 
};