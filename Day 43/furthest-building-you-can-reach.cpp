class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Min-heap (priority queue) to store the differences in height where we
        // used a ladder
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate through each building, except the last one
        for (int i = 0; i < heights.size() - 1; ++i) {
            // Calculate the height difference between the current building and
            // the next one
            int diff = heights[i + 1] - heights[i];

            // If the next building is higher
            if (diff > 0) {
                // Push the difference into the min-heap
                pq.push(diff);

                // If we have used more ladders than available
                if (pq.size() > ladders) {
                    // Use bricks instead of a ladder for the smallest
                    // difference
                    int smallest_diff = pq.top();
                    pq.pop();
                    bricks -= smallest_diff;

                    // If we don't have enough bricks to cover the difference
                    if (bricks < 0) {
                        // Return the index of the last building we can reach
                        return i;
                    }
                }
            }
        }

        // If we managed to reach the last building, return its index
        return heights.size() - 1;
    }
};
