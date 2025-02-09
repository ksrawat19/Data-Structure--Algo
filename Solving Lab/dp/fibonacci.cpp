// 📂 509. Fibonacci Number (leetcode)
#include <iostream>
#include <vector>
using namespace std;

// using top-down Approach (recursion + memoization)
class Solution {
    public:
    int memoisation(int n, vector<int>& dp){
        if(n==0 || n==1) return n;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = memoisation(n-2, dp) + memoisation(n-1, dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int>v (n+1, -1);
        return memoisation(n, v);
    }
};
// using bottom-up Approach (itertive + tabulation)
class Solution {
public:
    int fib(int n) {
        vector<int>dp (n+1, -1);
        dp[0] = 0;
        if(n==0) return dp[n];
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
// using space optimization (only if solution have any pattern)
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        int prev = 0;
        int curr = 1;

        int ans = -1;
        for(int i=2; i<=n; i++){
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
};