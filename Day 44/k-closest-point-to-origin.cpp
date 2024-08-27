class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store the closest k points. The pair contains the
        // distance and the point itself.
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            // Calculate the squared distance from the origin
            int dist = point[0] * point[0] + point[1] * point[1];

            // If the heap has less than k points, push the current point
            if (maxHeap.size() < k) {
                maxHeap.push({dist, point});
            }
            // If the heap is full and the current point is closer than the
            // farthest point in the heap
            else if (dist < maxHeap.top().first) {
                maxHeap.pop();               // Remove the farthest point
                maxHeap.push({dist, point}); // Push the current point
            }
        }

        // Extract the k closest points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};