// Function to find length of shortest common supersequence of two strings.

#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    
    int solve(string &s1, string &s2, int m, int n){
        if(m == 0 || n == 0){
            return m+n;
        }
        
        if(s1[m-1] == s2[n-1]){
            return 1 + solve(s1, s2, m-1, n-1);
        }
        else {
            return 1 + min(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
        }
        
        return 0;
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        return solve(s1, s2, m, n);
        
    }
};

// Memoization
class Solution {
  public:
    int solve(string &s1, string &s2, int m, int n, vector<vector<int>> &dp){
        if(m == 0 || n == 0){
            return m+n;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = 1 + solve(s1, s2, m-1, n-1, dp);
        }
        else {
            return dp[m][n] = 1 + min(solve(s1, s2, m-1, n, dp), solve(s1, s2, m, n-1, dp));
        }
        
        return 0;
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        
        return solve(s1, s2, m, n, dp);
        
    }
};

//Tabulation
// TC -> O(mn) SC -> O(mn)
class Solution {
  public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        // dp[i][j] -> shortest common supersequence till s1->length i and s2->length j
        
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i+j;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
        
    }
};

// Using LCS Code
// TC -> O(m*n) SC -> O(m*n)
class Solution {
  public:
    int shortestCommonSupersequence(string &s1, string &s2) {
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
        
        int lenlcs = dp[m][n]; // common part in both
        
        return lenlcs + (m - lenlcs) + (n - lenlcs);
        
    }
};