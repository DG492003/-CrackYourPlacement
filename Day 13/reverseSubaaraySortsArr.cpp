// Approach ->
//     Time Complexity: O(n)
//     Auxiliary Space: O(1)

// Initialize two variables x and y with -1.
// Iterate over the array.
//     -> Find the first number for which a[i] > a[i+1] and store it into x. 
//     -> Similarly, Store index i+1 as well into y, As this will keep track of the ending of the subarray which is needed to reverse.
// Check if x == -1 then array is already sorted so return true.
// Otherwise, reverse the array from index x to index y.
//     -> Traverse the array to check for every element is sorted or not.
//     -> If not sorted, return false.
// Finally, return true.

#include <bits/stdc++.h> 
using namespace std; 

bool sortArr(int a[], int n) { 
    // initialise pointers 
	int x = -1; 
	int y = -1; 
    // traverse the arr 
	for (int i = 0; i < n - 1; i++) { 
        // store sorted part starting index 
		if (a[i] > a[i + 1])
			if (x == -1)
				x = i; 
        // update the last index 
			y = i + 1; 
	} 
    // if x == -1 then already sorted 
    // else just reversed subarray between x and y
	if (x != -1) { 
		reverse(a + x, a + y + 1); 
        // traverse again to check sorted or not
		for (int i = 0; i < n - 1; i++) { 
			if (a[i] > a[i + 1]) { 
				return false; 
				return 0; 
			} 
		} 
	} 

	return true; 
} 

// Driver Program 
int main() { 
	int arr[] = { 1, 2, 5, 4, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	sortArr(arr, n) ? (cout << "Yes" << endl) : (cout << "No" << endl); 
	return 0; 
} 

