/* Leetcode 1911 
The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.
For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).*/ 


#include <vector>
using namespace std;

// Basic recursion
class Solution {
public:
    long long solve(int i, vector<int> &nums, long long evenSum, long long oddSum, int cnt){
        if(i >= nums.size()){
            return evenSum - oddSum;
        }
        // take 
        long long take;
        if(cnt % 2 == 0){
            take = solve(i+1, nums, evenSum + nums[i], oddSum, cnt+1);
        } else {
            take = solve(i+1, nums, evenSum , oddSum + nums[i], cnt+1);
        }

        //skip
        long long skip = solve(i+1, nums, evenSum, oddSum, cnt);

        return max(take, skip);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        return solve(0, nums, 0, 0, 0);
    }
};

// Memoization
class Solution {
public:
    long long solve(int i, vector<int> &nums, bool flag, vector<vector<long long>> &dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][flag] != -1){
            return dp[i][flag];
        }
        long long skip = solve(i+1, nums, flag, dp);

        int val = nums[i];
        if(flag == false){
            val = -val;
        } 
        long long take = solve(i+1, nums, !flag, dp) + val;;

        return dp[i][flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        // dp[index][flag]
        return solve(0, nums, true, dp);
    }
};

// Bottom-up
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        // dp[i][even] => num at index i is added to a subsquence and making it even length 
        // even length seq => + (a1) - (a2) + (a3) - (a4)  => prev 3 el are odd length
        // take  t[i][even] = t[i-1][odd] - nums[i]; taking num makes it even
        // skip  t[i][even] = t[i-1][even];  resulting should be even

        // dp[i][odd] => num at index i is added to a subsquence and making odd length
        // +(a1) - (a2) + (a3)
        // take  t[i][odd] = t[i-1][even] + nums[i];
        // skip  t[i][odd] = t[i-1][odd];

        // even : 0 && odd : 1
        
        for(int i = 1 ; i <= n ; i++){
            //dp[i][flag] = max(take, skip)
            // change nums[i] to nums[i-1] because of 1 based indexing in dp nums[1] -> nums[0]
            dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
        }

        return max(dp[n][0], dp[n][1]);
        // TC - O(n) , SC - O(n)
    }
};