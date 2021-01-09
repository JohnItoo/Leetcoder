class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return n;
        if (n == 1) return nums[0];
        vector<vector<int> > dp(n + 2, vector<int>(2, 0));

        // dp[i][0] max selecting current house
        // dp[i][1] max not selecting current house
        // At every point i we need to know if we are selecting or not so
        // ability to select is an additional state.

        dp[1][0] = nums[0];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + nums[i - 1];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[n][0], dp[n][1]);
    }
};