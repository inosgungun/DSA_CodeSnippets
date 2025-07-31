// s1 = ace and s2 = abcde
// find longest common subsequence ("ace")

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// TC -> O(m*n) , SC -> O(m*n)
class Solution {
public:
    string longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // row 1 and col 1 will be zero because length 0 of any string doesn't give anything common

        for(int i = 1 ; i < m+1 ; i++){
            for(int j = 1 ; j < n+1 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        string lcs = "";
        int i = m;
        int j = n;

        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            } 
            else {
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else j--;
            }
        }

        reverse(begin(lcs), end(lcs));

        return lcs;
    }
};