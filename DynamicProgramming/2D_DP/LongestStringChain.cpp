// Leetcode 1048

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comparator(const string &a, const string &b){
        return a.size() < b.size();
    }

    bool isPredecessor(const string &a, const string &b){
        int m = a.size(), n = b.size();
        if(n - m != 1) return false;

        int i = 0, j = 0;
        while(j < n){
            if(i < m && a[i] == b[j]){
                i++;
            }
            j++;
        }
        return i == m;
    }

    int LIS(int i, int p, vector<string> &words, vector<vector<int>> &dp){
        if(i == words.size()){
            return 0;
        }
        if(p != -1 && dp[i][p+1] != -1){
            return dp[i][p+1];
        }

        int take = 0;
        if(p == -1 || isPredecessor(words[p], words[i])){
            take = 1 + LIS(i+1, i, words, dp);
        }
        int skip = LIS(i+1, p, words, dp);

        if(p != -1){
            dp[i][p+1] = max(take, skip);
        }
        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comparator);
        // dp[i][p+1]: longest chain starting at index i, previous index p (offset by +1)
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return LIS(0, -1, words, dp);
    }
};


// Tabulation
class Solution {
public:
    static bool comparator(const string &a, const string &b){
        return a.size() < b.size();
    }

    bool isPredecessor(const string &a, const string &b){
        int m = a.size(), n = b.size();
        if(n - m != 1) return false;

        int i = 0, j = 0;
        while(j < n){
            if(i < m && a[i] == b[j]){
                i++;
            }
            j++;
        }
        return i == m;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comparator);
        
        vector<int> dp(n, 1);
        int maxL = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxL = max(maxL, dp[i]);
                }
            }
        }

        return maxL;
    }
};
