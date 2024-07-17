// Approach -> Tc - O(nlogn) due to sorting
// simply sort the array and iterate it in 'M' sized subarray and find the difference of (max number) and (min number) and store minimum difference among all the M subarray slides.


class solution{
    public:
        long long findMinDiff(vector<long long> a, long long n, long long m){
        //code here
            // sort the arr
            sort(a.begin(),a.end());
            // intialise pointers and minimum diffrence variable
            int left = 0, right = m-1;
            long long  minDiff = INT_MAX;
            // traverse the arr
            while(right < n){
                // find the diff. b/w max & min element 
                long long diff = a[right] - a[left];
                // taking only min. differences
                minDiff = min(minDiff, diff);
                // increment pointers
                right++;
                left++;
            }
            // return the answer
            return minDiff;
        } 
};