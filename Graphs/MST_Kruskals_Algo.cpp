// Sort in ascending order based on weight
// check if both nodes are connected or not
// adj -> {{u1, v1, wt1}, {u2, v2, wt2}, ...}
// Sort based on wt
// DSU is used here

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int detectCycle(int V, vector<int> adj[]) {
        
        parent.resize(V);
        rank.resize(V);
        
        for(int i = 0 ; i <V ; i++){
            parent[i] = i;
        }
        
        for(int u = 0 ; u < V ; u++){
            for(int &v : adj[u]){
                if(u < v){
                    int parent_u = find(u);
                    int parent_v = find(v);
                    
                    if(parent_u == parent_v){
                        return 1;
                    }
                    
                    unionSet(u,v);
                }
            }
        }
        
        return 0;
        
    }
  
    int Kruskal(vector<vector<int>> &vec){
        int sum = 0;

        // O(e * (4*alpha))
        for(auto &temp : vec){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v){
                unionSet(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    
    // Function to find sum of weights of edges of the Minimum Spanning Tree - Kruskal's Algo.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        parent.resize(V);
        rank.resize(V);
        
        for(int i = 0 ; i < V ; i++){
            parent[i] = i;
        }
        
        vector<vector<int>> vec; 

        // O (v + e)
        for(int u = 0 ; u < V ; u++){
            
            for(auto &it : adj[u]){
                
                int v = it[0];
                int wt = it[1];
                
                vec.push_back({u, v, wt});
            }
        }
        
        auto comparator = [&](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        };
        
        sort(vec.begin(), vec.end(), comparator); // O(elog(e))
        
        return Kruskal(vec);
        
    }
};
