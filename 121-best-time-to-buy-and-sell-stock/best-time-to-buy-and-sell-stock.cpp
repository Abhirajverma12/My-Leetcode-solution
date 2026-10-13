class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int transactions,
              vector<vector<vector<int>>>& dp) {

        if (i == prices.size()) return 0;
        if (transactions == 1) return 0;

        if (dp[i][buy][transactions] != -1) {
            return dp[i][buy][transactions];
        }

        if (buy == 1) {
            int choice1 = -prices[i]
                        + solve(prices, i + 1, 0, transactions, dp);
            int choice2 = solve(prices, i + 1, 1, transactions, dp);

            return dp[i][buy][transactions] = max(choice1, choice2);
        } else {
            int choice1 = prices[i]
                        + solve(prices, i + 1, 1, transactions + 1, dp);
            int choice2 = solve(prices, i + 1, 0, transactions, dp);

            return dp[i][buy][transactions] = max(choice1, choice2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1))
        );

        return solve(prices, 0, 1, 0, dp);
    }
};