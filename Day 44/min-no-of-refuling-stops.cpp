class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max-heap to store the fuel available at stations we've passed
        priority_queue<int> maxHeap;

        int currentFuel = startFuel; // Current fuel in the car
        int currentPosition = 0;     // Current position of the car
        int refuelStops = 0;         // Number of refueling stops made
        int stationIndex = 0;        // Index to iterate through stations

        // Continue until we reach or surpass the target
        while (currentFuel < target) {
            // Add all reachable stations' fuel to the max-heap
            while (stationIndex < stations.size() && stations[stationIndex][0] <= currentFuel) {
                maxHeap.push(stations[stationIndex][1]);
                stationIndex++;
            }

            // If no more stations are reachable and we haven't reached the
            // target
            if (maxHeap.empty()) {
                return -1; // Not possible to reach the target
            }

            // Refuel with the largest amount of fuel available
            currentFuel += maxHeap.top();
            maxHeap.pop();
            refuelStops++;
        }

        return refuelStops;
    }
};