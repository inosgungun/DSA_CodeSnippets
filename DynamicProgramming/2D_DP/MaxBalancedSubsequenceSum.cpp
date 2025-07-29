// Leetcode 2926

/* You are given a 0-indexed integer array nums.
A subsequence of nums having length k and consisting of indices i0 < i1 < ... < ik-1 is balanced if the following holds:

 nums[ij] - nums[ij-1] >= ij - ij-1, for every j in the range [1, k - 1].

A subsequence of nums having length 1 is considered balanced.
Return an integer denoting the maximum possible sum of elements in a balanced subsequence of nums.
A subsequence of an array is a new non-empty array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.*/

#include <vector>
using namespace std;

// Memoization
class Solution {
public:
    long long solve(int prev, int i, vector<int> &nums, vector<vector<long long>> &dp){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[prev + 1][i] != -1){
            return dp[prev + 1][i];
        }

        long long taken = LLONG_MIN;
        long long not_taken = LLONG_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev){
            taken = nums[i] + solve(i, i+1, nums, dp);
        }
        not_taken = solve(prev, i+1, nums, dp);

        return dp[prev + 1][i] = max(taken, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi <= 0) return maxi;

        // dp[prev + 1][i], where prev ranges from -1 to n-1
        vector<vector<long long>> dp(n+1, vector<long long>(n, -1));
        return solve(-1, 0, nums, dp);
    }
};

// Bottom-up
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi <= 0) return maxi;

        vector<long long> dp(n);
        // dp[i] -> max maxBalanaceSubsequenceSum till index i
        for(int i = 0 ; i < n ; i++){
            dp[i] = nums[i];
        }
        
        long long maxSum = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] - i >= nums[j] - j){
                    dp[i] = max<long long>(dp[i], dp[j]+nums[i]);
                    maxSum = max(maxSum, dp[i]);
                }
            }
        }

        return maxSum > maxi ? maxSum : maxi;
    }
};