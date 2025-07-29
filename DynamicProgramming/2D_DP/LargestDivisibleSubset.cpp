// Leetcode 368

/* Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.*/

#include <vector>
#include <algorithm>
using namespace std;

// Recursion
class Solution {
public:
    void solve(int i, vector<int> &temp, vector<int> &result, vector<int>&nums, int prev){
        if(i >= nums.size()){
            if(temp.size() > result.size()){
                result = temp;
            }
            return;
        }
        if(prev == -1 || nums[i] % prev == 0){
            temp.push_back(nums[i]);
            solve(i+1, temp, result, nums, nums[i]);
            temp.pop_back();
        }
        solve(i+1, temp, result, nums, prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<int> result;
        int prev = -1;
        solve(0, temp, result, nums, prev);

        return result;
    }
};

// Tabulation
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);

        int last_chosen_index = 0;
        int maxL = 1;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] % nums[j] == 0){

                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prevIdx[i] = j;
                    }


                    if(dp[i] > maxL){
                        maxL = dp[i];
                        last_chosen_index = i;
                    }
                    
                }
            }
        }

        vector<int> result;
        while(last_chosen_index != -1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prevIdx[last_chosen_index];
        }

        return result;
    }
};