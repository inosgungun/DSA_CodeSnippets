// Eulerian Path :- A path of edges that visits all the edges in a graph exactly once.
// Not all graphs have an Euler Path, and carefully choose start node.

// Eulerian Circuit/Cycle :- An Eulerian path which end and starts on the same node.
// Can start from any node and end on any node.
// All nodes with have even degree.

// Semi Eulerian Graph :- Euler Path exist, but not Euler Circuit.
// Only Start and End node have odd degree, others have even degree.

// Non-degree wale vertices must be visited

/*
An Eulerian Path is a path in graph that visits every edge exactly once. An Eulerian 
Circuit is an Eulerian Path which starts and ends on the same vertex. Given an 
undirected connected graph with V nodes, and E edges, with adjacency list adj, return 2 
if the graph contains an eulerian circuit, else if the graph contains an eulerian path, 
return 1, otherwise, return 0.
*/

// TC: O(V+E)


#include <vector>
using namespace std;

class Solution {
public:

    void DFS(vector<int>adj[], int u, vector<bool>& visited) {
        visited[u] = true;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if(visited[*it] == false) {
                DFS(adj, *it, visited);
            }
        }
    }
    

    // Only needed if disconnected graph is given
    bool isConnected(int V, vector<int>adj[]) {
        vector<bool> visited(V, false);
        
        //Find a vertex with non-zero degree
        int nonZeroDegreeVertex = -1;
        for(int i = 0; i<V; i++) {
            if(adj[i].size() != 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }
        
        // Start DFS traversal from a vertex with non-zero degree
        DFS(adj, nonZeroDegreeVertex, visited);
        
        // Check if all non-zero degree vertices are visited
        for(int i = 0; i<V; i++) {
            if(visited[i] == false && adj[i].size() > 0)
                return false;
        }
        return true;
    }

	int isEularCircuit(int V, vector<int>adj[]){
	    
	    //Check if all non-zero degree vertices are connected
	    if(isConnected(V, adj) == false) {
	        return 0; //Non-Eulerian
	    }
	    
	    //Count vertices with odd degree
	    int oddCount = 0;
	    for(int i = 0; i<V; i++) {
	        if(adj[i].size()%2 != 0) {
	            oddCount++;
	        }
	    }
	    
	    // If count is more than 2, then graph is not Eulerian
        if (oddCount > 2)
            return 0; //Non-Eulerian
        
        if(oddCount == 2) {
            return 1; //Semi-Eulerian (It has only Euler Path)
        }
        
        return 2; //(Euler Circuit)
	    
	}
};

