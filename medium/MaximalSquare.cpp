class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 4, vector<int>(n + 4, 0));
        int ans = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '0') continue;
                if (dp[i - 1][j - 1] == 0) {
                    dp[i][j] = 1;
                } else {
                    int prev = dp[i - 1][j - 1];
                    int ct = 1;
                    while (ct <= prev && matrix[i - 1][j - ct - 1] == '1' &&
                           matrix[i - ct - 1][j - 1] == '1') {
                        ct++;
                    }
                    dp[i][j] = ct;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};