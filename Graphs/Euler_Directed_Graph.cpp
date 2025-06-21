// souce -> outdegree[node] - indegree[node] = 1
// destination -> indegree[node] - outdegree[node] = 1;
// other nodes -> indegree[node] == outdegree[node]

// all nodes with equal indegree and outdegree => Eulerian Circuit
// If Eulerian circuit exists, any node can be start node

/*  Hierholzer's Algorithm 
    1. Build Adjacency List
    2. Build Indegree and Outdegree
    3. Find the startNode of Euler Path
    4. Find Euler Path store in a vector
    TC:- O(V+E) 
    SC:- O(V+E)
*/ 

/* You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. 
   An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, 
   we have endi-1 == starti.
   Return any valid arrangement of pairs.

   Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
   Output: [[11,9],[9,4],[4,5],[5,1]]
   Explanation:
   This is a valid arrangement since endi-1 always equals starti.
   end0 = 9 == 9 = start1 
   end1 = 4 == 4 = start2
   end2 = 5 == 5 = start3
*/

#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Euler Path 
        // All edges are visited only once

        unordered_map<int, vector<int>> adj;
        vector<vector<int>> ans;

        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        for(auto &it: pairs){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        int start = pairs[0][0];

        for(auto &it : adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                start = node;
                break;
            }
        }

        stack<int> st;
        vector<int> eulerPath;
        st.push(start);

        while(!st.empty()){
            int curr = st.top();

            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else {
                eulerPath.push_back(curr);
                st.pop();
            }
            
        }

        reverse(eulerPath.begin(), eulerPath.end());
        for(int i = 0 ; i < eulerPath.size()-1 ; i++){
            ans.push_back({eulerPath[i], eulerPath[i+1]});
        }

        return ans;
    }
};