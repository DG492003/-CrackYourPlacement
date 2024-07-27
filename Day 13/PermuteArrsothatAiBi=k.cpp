// Approach -> TC - O(nlogn) due to sort

// The idea is to sort one array in ascending order and another array in descending order and if any index does not satisfy the condition a[i] + b[i] >= K then print “No”, else print “Yes”.
// Proof,
// Assume asort[] be sorted a[] in ascending order and bsort[] be sorted b[] in descending order. 
// Let new permutation b[] is created by swapping any two indices i, j of bsort[], 
// Case 1:
//     i < j and element at b[i] is now bsort[j]. 
//     Now, asort[i] + bsort[j] < K, because bsort[i] > bsort[j] as b[] is sorted in decreasing order and we know asort[i] + bsort[i] < k.
// Case 2: 
//     i > j and element at b[i] is now bsort[j]. 
//     Now, asort[j] + bsort[i] < k, because asort[i] > asort[j] as a[] is sorted in increasing order and we know asort[i] + bsort[i] < k.

class solution{
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        
        // Sort the array a[] in increasing order.
        sort(a, a + n);
        // Sort the array b[] in decreasing order.
        sort(b, b + n, greater<int>());
        
        // traverse the arrs
        for(int i=0;i<n;i++)
            // if this condition comes means false 
            if(a[i] + b[i] < k)
                return false;
        
        // if loops run completely then for all value of i condition true
        return true;
                
    }
};