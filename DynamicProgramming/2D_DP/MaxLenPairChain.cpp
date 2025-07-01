// Leetcode 646
// Same as LIS

// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
// Return the length longest chain which can be formed.
// You do not need to use up all the given intervals. You can select pairs in any order.


#include <vector>
#include <algorithm>
using namespace std;

// Memoization
class Solution {
public:
    int LIS(int i, vector<vector<int>>& pairs, vector<vector<int>> &dp, int p){
        if(i >= pairs.size()){
            return 0;
        }
        if(p != -1 && dp[i][p] != -1){
            return dp[i][p];
        }

        int take = 0;
        if(p == -1 || pairs[p][1] < pairs[i][0]){
            take = LIS(i+1, pairs, dp, i) + 1;
        }
        int skip = LIS(i+1, pairs, dp, p);

        if(p != -1){
            dp[i][p] = max(take, skip);
        }

        return max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return LIS(0, pairs, dp, -1);
    }
};


// Tabulation
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort (pairs.begin(), pairs.end());

        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};