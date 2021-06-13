class Solution {
   public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = startFuel;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - 1][j - 1] >= stations[i - 1][0]) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1]);
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            if (dp[n][i] >= target) return i;
        }
        return -1;
    }
};