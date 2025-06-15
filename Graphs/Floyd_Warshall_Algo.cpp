// Find shorsted path from all vertices to all vertices
// Can also detect negative cycles
// Time Complexity: O(n^3)


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &grid) {
        int n = grid.size();

        // Replace -1 with INF
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == -1) {
                    grid[i][j] = INT_MAX;
                }
            }
        }

        // Floyd-Warshall algorithm
        for (int via = 0 ; via < n ; via++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (grid[i][via] != INT_MAX && grid[via][j] != INT_MAX) {
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }

        // Replace INF back to -1
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == INT_MAX) {
                    grid[i][j] = -1;
                }
            }
        }
    }
};
