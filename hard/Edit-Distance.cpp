//THIS IS A CLASSIC PROBLEM SOLVED USING LEVINSTHEIN DISTANCE.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int INF = 1e8 + 7;
        vector<vector<int> > dp(n + 5, vector<int>(m + 5, INF));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int changeCost = word1[i - 1] == word2[j - 1] ? 0 : 1;
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + changeCost);

            }
        }

        return dp[n][m];

    }
};