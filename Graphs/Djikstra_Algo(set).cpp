#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
#include <set>
using namespace std;


class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }

        set<pair<int, int>> st;
        vector<int> ans(V, INT_MAX);
        
        ans[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            
            st.erase(it);

            for (auto &vec : adj[node]) {
                
                int adjNode = vec.first;
                int dist = vec.second;

                if (d + dist < ans[adjNode]) {
                    
                    if(ans[adjNode] != INT_MAX){
                        st.erase({ans[adjNode], adjNode});
                    }
                    
                    ans[adjNode] = d + dist;
                    st.insert({d + dist, adjNode});
                }
            }
        }

        return ans;
    }
};

// 1 push operation -> log(v)
// worst case = v vertex can connect to (v-1) ~ V^2 edges ~ E 

// TC -> v *(log(v) + E.log(v)) -> V.log(v)(1 + E) ~ O(E.v.log(v))

