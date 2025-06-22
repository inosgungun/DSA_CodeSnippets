// Leetcode 70

#include <vector>
using namespace std;

// Brute Force (Recursion) TC:- O(2^n)
class Solution {
public:
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return one_step + two_step;
    }
    int climbStairs(int n) {
        return solve(n);
    } 
};

// Memoization (Top Down) TC:- O(n), SC:- O(n)
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int one_step = solve(n-1, dp);
        int two_step = solve(n-2, dp);

        return dp[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    } 
};

// Tabulation (Bottom Up)
class Solution {
public:
    int climbStairs(int n) {
        // dp[n] -> no of ways to climb n stairs
        if(n <= 3){
            return n;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
         
        for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    } 
};

// Constant Space
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }

        int a = 1;
        int b = 2;
        int c;
         
        for(int i = 3 ; i <= n ; i++){
            c = b + a;
            a = b;
            b = c;
        }

        return c;
    } 
};