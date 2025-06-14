// Djikstra does not work with negative weights
// Obviously won't detect -ve cycles

// Bellman Ford only word on directed graphs
// Do relaxation (v-1) times of each edge in same order of given edges

#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1 ; i <= V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative-weight cycle
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                return {-1}; // Negative weight cycle detected
            }
        }

        return dist;
    }
};



// Djikstra

// Works on both Directed and Undirected Graphs
// Can't work with negative edges
// Can't be applied for -ve cycles

// Bellman Ford 

// Works only on directed graphs
// works for -ve edges too
// helps detect -ve cycles
