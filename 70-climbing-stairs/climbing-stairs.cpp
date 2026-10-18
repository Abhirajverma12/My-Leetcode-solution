class Solution {
public:
// this problem is same as the FIBONACCI Series............
    int solvedp(int n ,vector<int>&dp){
        if(n<=1)return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = solvedp(n-1,dp)+solvedp(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solvedp(n,dp);
    }
};