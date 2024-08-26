class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = DBL_MAX;  // Initialize the answer to the maximum possible value
        int qualitySum = 0;  // Variable to keep track of the sum of qualities of the selected workers
        vector<pair<double, int>> workers;  // Vector to store wage-to-quality ratios and quality
        
        priority_queue<int> Mheap;  // Max-heap to store the qualities of workers
        
        // Step 1: Populate the workers vector with wage-to-quality ratio and quality
        for(int i = 0; i < quality.size(); i++)
            workers.emplace_back((double)wage[i] / quality[i], quality[i]);

        // Step 2: Sort workers by wage-to-quality ratio
        sort(workers.begin(), workers.end());

        // Step 3: Iterate over the sorted workers to calculate the minimum cost
        for(const auto &[wageQ, Q] : workers) {
            Mheap.push(Q);  // Add the quality of the current worker to the max-heap
            qualitySum += Q;  // Update the sum of qualities

            // If the number of workers in the heap exceeds k, remove the worker with the highest quality
            if(Mheap.size() > k) {
                qualitySum -= Mheap.top();
                Mheap.pop();
            }

            // Calculate the cost if we have exactly k workers
            if (Mheap.size() == k)
                ans = min(ans, qualitySum * wageQ);
        }
        
        return ans;  // Return the minimum cost found
    }
};
