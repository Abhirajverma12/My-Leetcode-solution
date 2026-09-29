class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int transactionsLeft,
              vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || transactionsLeft == 0) return 0;

        if (dp[i][buy][transactionsLeft] != -1)
            return dp[i][buy][transactionsLeft];

        if (buy == 1) {
            int purchase = -prices[i]
                         + solve(prices, i + 1, 0, transactionsLeft, dp);
            int skip = solve(prices, i + 1, 1, transactionsLeft, dp);

            return dp[i][buy][transactionsLeft] = max(purchase, skip);
        }

        int sell = prices[i]
                 + solve(prices, i + 1, 1, transactionsLeft - 1, dp);
        int hold = solve(prices, i + 1, 0, transactionsLeft, dp);

        return dp[i][buy][transactionsLeft] = max(sell, hold);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1))
        );

        return solve(prices, 0, 1, 1, dp);
    }
};