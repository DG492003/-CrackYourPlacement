// Approach -> Tc - O(n * n! + nlogn)
// we use greedy algorithm and recursion

// steps->
//     -> firts pick an element and then see possible cases and maintain a data structure and map
//     -> if size of data recusrion equal to arr then terminate the recursion
//     -> after picking the element perform recursion on remaining part then after that mark in map as unpicked and remove from data structure.
//     -> After that sort it and remove duplicates

class Solution {
  private:
    void permute(vector<int> &arr, vector<int>& ds, vector<vector<int>> &permutations, int frq[]){
        // if size of given arr and data structure is same
        if(ds.size() == arr.size()){
            // store the answer and return/end the recursion
            permutations.push_back(ds);
            return;
        }
        // else
        for(int i=0;i<arr.size();i++){
            // check the element picked or not
            if(frq[i] == 0){
                // add the element in data structure
                ds.push_back(arr[i]);
                // if not, then mark it
                frq[i] = 1;
                // call the recursion
                permute(arr, ds, permutations, frq);
                // after recursion mark it as a unpicked
                frq[i] = 0;
                // also remove it from data structure
                ds.pop_back();
            }
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // to store all permutations
        vector<vector<int>> permutations;
        // to store permuation
        vector<int> ds;
        // to track whether element is picked or not
        int frq[n] = {0};
        for(int i=0;i<arr.size();i++) 
            frq[i] = 0;
        
        // call the recursive function
        permute(arr, ds, permutations, frq);
        
        // to remove duplicates, first sort it
        sort(permutations.begin(),permutations.end());
        // remove consecutive duplicate elements
        // After this step, the unique elements are at the beginning of the container, and the remaining elements (from it to ans.end()) are unspecified.
        auto it = unique(permutations.begin(), permutations.end()); 
        // to remove all the duplicates from the vector 
        permutations.erase(it, permutations.end()); 
        
        // return the answer
        return permutations;
        
    }
};