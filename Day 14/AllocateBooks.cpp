// Appoach ->
// Time Complexity: 
//     O(N * log(sum(arr[])-max(arr[])+1)), N = size of arr, 
//     Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.


// Algorithm:
//     - If m > n: In this case, book allocation is not possible and so, we will return -1.
//     - Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
//     - Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
//     mid = (low+high) // 2 ( ‘//’ refers to integer division)
//     - Eliminate the halves based on the number of students returned by countStudents():
//     - We will pass the potential number of pages, represented by the variable 'mid', to the ‘countStudents()' function. This function will return the number of students to whom we can allocate the books.
//         - If students > m: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
//         - Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
//     - Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

// // Returning the low pointer as the answer makes sense because it represents the smallest maximum page allocation found that satisfies the problem constraints.
// Example:
//     Consider you have books with the following pages: [12, 34, 67, 90] and you have 2 students.
//     Initial bounds: low = 90 (largest single book), high = 203 (sum of all pages).
// Binary search steps:
//     mid = (90 + 203) / 2 = 146. Check if 146 pages per student is feasible.
//     If feasible, try lower by setting high = mid - 1.
//     If not feasible, try higher by setting low = mid + 1.
// Continue until low exceeds high.
//     After the binary search completes, low will represent the smallest maximum page allocation.
//     Returning low ensures you get the optimal solution.

class Solution {
  private:
    // helper function hich counts the students as per conditions
    long long countStudents(int arr[], int n, int pages) {
        // initialise the student variable and page variable
        int students = 1;
        long long pagesStudent = 0;
        // traverse the arr
        for (int i = 0; i < n; i++) {
            // check if sum of pages is smaller than expected min. page
            if (pagesStudent + arr[i] <= pages)
                //add pages to current student
                pagesStudent += arr[i];
                
            else {
                //add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
}
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        // book allocation is impossible if students is more compare to books
        if (m > n) return -1;
        // low starts with a book have max no. of pages
        int low = *max_element(arr, arr+n);
        // high starts with total no. of pages
        int high = accumulate(arr, arr+n, 0);
        
        // traverse this range and check which allocation is good
        while (low <= high) {
            // get the mid
            int mid = (low + high) / 2;
            // get the no. of students if mid no. of pages distributed
            int students = countStudents(arr,n, mid);
            // if no.of students is more than m
            // we need to divide more pages so increase 
            if (students > m)
                low = mid + 1;
            // if student is less then divide less pages
            else
                high = mid - 1;
        }
        return low;
    }
};