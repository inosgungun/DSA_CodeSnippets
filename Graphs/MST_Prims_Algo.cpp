#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // {wt, node}
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
          
            pq.pop();
            
            if(vis[node] == 1){
                continue;
            }
            
            vis[node] = 1;
            sum += wt;
            
            for(auto &it : adj[node]){
                int ngbr = it[0];
                int n_wt = it[1];
                
                if(!vis[ngbr]){
                    pq.push({n_wt, ngbr});
                }
            }
        }
        return sum;
        
    }
};
