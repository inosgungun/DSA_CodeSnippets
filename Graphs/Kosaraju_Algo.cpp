// To find Strongly Connected Components (SCC)


#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:

    void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                dfsFill(v, adj, visited, st);
            }
        }
    
        st.push(u);
    }
    
    void dfsTraversal(int u, vector<vector<int>> &adjReversed, vector<bool> &visited){
        visited[u] = true;
        
        for(int &v : adjReversed[u]){
            if(!visited[v]){
                dfsTraversal(v, adjReversed, visited);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        
        // step 1:- store in topological order in stack;
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        
        // step 2:- Make a reversed Graph
        vector<vector<int>> adjReversed(V);
        
        for(int u = 0 ; u < V ; u++){
            // u -> v
            for(int &v : adj[u]){
                adjReversed[v].push_back(u);
            }
        }
        
        // step 3:- Call dfs based on stack order
        int count = 0;
        visited = vector<bool>(V, false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfsTraversal(node, adjReversed, visited);
                count++;
            }
        }
        
        return count;
        
    }
};