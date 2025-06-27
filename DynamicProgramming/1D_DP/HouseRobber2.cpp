// Leetcode 213

#include <vector>
using namespace std;

// Recursion + Memoization
class Solution {
public:
    int solve(int i, vector<int> &nums, int m, vector<int> &dp){
        if(i > m){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int steal = nums[i] + solve(i+2, nums, m, dp);
        int skip = solve(i+1, nums, m, dp);

        return dp[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> dp(n+1, -1);
        
        // Case 1: Take 0th house
        int option1 = solve(0, nums, n-2, dp);

        dp = vector<int>(n+1, -1);
        // Case 2: Take 1st house
        int option2 = solve(1, nums, n-1, dp);

        return max(option1, option2);
    }
};

// Tabulation (Bottom Up) TC:- O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> dp(n+1, 0);
        // dp[i] -> money stolen when you have i houses
        
        // case1 :- start from 1st house
        for(int i = 1 ; i <= n-1 ; i++){
            int skip = dp[i-1];
            int take = nums[i-1] + (i-2 >= 0 ? dp[i-2] : 0);
            dp[i] = max(skip, take);
        }
        int result1 = dp[n-1];

        dp.clear();
        dp[0] = 0;
        dp[1] = 0; // skip first house

        // case2 :- take from 2nd house
        for(int i = 2 ; i <= n ; i++){
            int skip = dp[i-1];
            int take = nums[i-1] + (i-2 >= 0 ? dp[i-2] : 0);
            dp[i] = max(skip, take);
        }

        int result2 = dp[n];
        
        return max(result1, result2);
    }
};


// constant space
class Solution {
public:
    int solve(vector<int> &nums, int l , int r){

        int prevprev = 0;
        int prev = 0;
    
        for(int i = l ; i <= r ; i++){
            int skip = prev;
            int take = nums[i] + prevprev;
            int temp = max(skip, take);

            prevprev = prev;
            prev = temp;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0], nums[1]);
        }
        
        int take_first_house = solve(nums, 0, n-2);
        int skip_first_house = solve(nums, 1, n-1);
      
        return max(take_first_house , skip_first_house);
    }
};