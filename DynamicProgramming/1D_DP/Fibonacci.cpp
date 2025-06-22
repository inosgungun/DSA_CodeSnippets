#include <vector>
using namespace std;

// Recursion TC: O(2^n)
class Solution {
public:
    int fib(int n) {
        if(n <= 1){ // base case:- lowest possible valid of the param
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

// Memoization
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// Bottom Up(Tabulation) TC:- O(n) SC:- O(n)
class Solution {
public:
    int fib(int n) {
        // state define
        // dp[i] -> i th fibonacci number 
        if(n <= 1){
            return n;
        }
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


// Constant Space SC:- O(1) TC:- O(n)
class Solution {
public:
    int fib(int n) {
        // ith state depend on last 2 states only 
        // so lets store them only in variables
        if(n <= 1){
            return n;
        }
        int a = 0;
        int b = 1;
        int c;

        for(int i = 2 ; i <= n ; i++){
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
