class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minInf = -1e9 - 7;
        vector<vector<int> > dp(n + 1, vector<int>(2, 0));

        dp[1][1] = -prices[0];
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            int maxPrevBuy = -1e9 - 7;
            for (int j = 1; j <= i - 1; j++) {
                maxPrevBuy = max(maxPrevBuy, dp[j][1]);
            }
            int maxPrevSell = -1e9 - 7;
            for (int j = 0; j <= i - 2; j++) {
                maxPrevSell = max(maxPrevSell, dp[j][0]);
            }
            dp[i][0] = maxPrevBuy + prices[i - 1];
            dp[i][1] = maxPrevSell - prices[i - 1];
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};