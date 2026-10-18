class Solution {
public:
int findfib(int n ,vector<int>& dp){
    if(n<=1)return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = findfib(n-1,dp)+ findfib(n-2,dp);
}
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return findfib(n,dp);
    }
};