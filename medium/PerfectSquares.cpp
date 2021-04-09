class Solution {
   public:
    int numSquares(int n) {
        vector<long long> perfectSquares;
        int i = 1;
        long long INF = 10009;
        vector<long long> dp(n + 9, INF);
        dp[0] = 0;
        while (i * i <= n) {
            perfectSquares.push_back(i * i * 1LL);
            dp[i * i] = 1;
            i++;
        }
        int m = perfectSquares.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (perfectSquares[j] > i) break;
                dp[i] = min(dp[i], dp[i - perfectSquares[j]] + 1);
            }
        }
        return dp[n];
    }
};