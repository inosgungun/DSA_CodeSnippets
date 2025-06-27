// Leetcode 198

#include <vector>
using namespace std;

// Recursion
class Solution {
public:
    int solve(int i, vector<int> &nums){
        if(i >= nums.size()){
            return 0;
        }
        int steal = nums[i] + solve(i+2, nums);
        int skip = solve(i+1, nums);

        return max(steal, skip);
    }
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};

// Memoization (Top-Down)
class Solution {
public:
    int solve(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int steal = nums[i] + solve(i+2, nums, dp);
        int skip = solve(i+1, nums, dp);

        return dp[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
};

// Tabulation (Bottom Up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i] -> max stolen money till ith house
        vector<int> dp(nums.size() + 1, 0);
        // no house: i = 0 no money
        dp[0] = 0;
        // 1 house: i = 1 one house
        dp[1] = nums[0];

        for(int i = 2 ; i <= n ; i++){
            int steal = nums[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(steal, skip);
        }

        return dp[n];
    }
};

// Constant Space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i-1] -> prev result , dp[i-2] -> prevprev 
        // so at each step we only need prev and prevprev
        int prevprev = 0;
        int prev = nums[0];

        for(int i = 2 ; i <= n ; i++){
            int steal = nums[i-1] + prevprev;
            int skip = prev;
            int temp = max(steal, skip);

            prevprev = prev;
            prev = temp;
        }

        return prev;
    }
};