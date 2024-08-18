// Time Complexity: O( N^M) (n raised to m)
// Space Complexity: O(N)

class solution{
private:
// Function to check if it's safe to color a node with a given color
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    // Check all adjacent nodes to ensure no adjacent node has the same color
    for (int k = 0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false; // Unsafe to color this node with 'col'
        }
    }
    return true; // Safe to color this node with 'col'
}

// Recursive function to solve the graph coloring problem using backtracking
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    // If all nodes are processed, coloring is successful
    if (node == N) {
        return true;
    }

    // Try all colors for the current node
    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
            color[node] = i; // Assign color 'i' to the node

            // Recursively try to color the next node
            if (solve(node + 1, color, m, N, graph)) return true;

            // If coloring fails, backtrack
            color[node] = 0;
        }
    }
    return false; // No valid coloring found for this node
}

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0}; // Array to store colors assigned to nodes

        // Start coloring from the first node
        return solve(0, color, m, n, graph);
    }
};