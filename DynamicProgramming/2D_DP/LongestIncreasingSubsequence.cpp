// Leetcode 300 
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include <vector>
using namespace std;

// Recursion
class Solution {
public:
    int solve(int i, vector<int> &nums, int p){
        if(i >= nums.size()){
            return 0;
        }
        // take
        int take;
        if(p == -1 || nums[i] > nums[p]){
            take = 1 + solve(i+1, nums, i);
        } 
        // skip
        int skip = solve(i+1, nums, p);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        // p -> prev index
        return solve(0, nums, -1);
    }
};

// Memoization 
// TC - O(n^2), SC - O(n^2)
class Solution {
public:
    int solve(int i, vector<int> &nums, int p, vector<vector<int>> &dp){
        if(i >= nums.size()){
            return 0;
        }
        // if p == -1 then dp[i][p] will give run time error p = -1 is invlaid index
        if(p != -1 &&  dp[i][p] != -1){
            return dp[i][p];
        }
        // take
        int take = 0;
        if(p == -1 || nums[i] > nums[p]){
            take = 1 + solve(i+1, nums, i, dp);
        } 
        // skip
        int skip = solve(i+1, nums, p, dp);
        
        if(p != -1){
            dp[i][p] = max(take, skip);
        }
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // p -> prev index
        // check recursion call -> 2 variables are changing
        // dp[i][p] => represent max longest subseq length till index i with prev el p

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, nums, -1, dp);
    }
};

// Bottom up
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
      
        vector<int> dp(n+1, 1);
        int maxLIS = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i] , dp[j] + 1);
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }

        return maxLIS;
    }
};