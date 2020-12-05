class Solution {
    int INF = 1e9 + 6;
    int dp[310][15];
    int D = 0;

    int solve(int i, int j, vector<int> &jd) {
        if (j == 1) {
            int mx = 0;
            int lft = i;
            while (lft < jd.size()) {
                mx = max(mx, jd[lft]);
                lft++;
            }
            return mx;
        }
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = INF;
        int hw = jd.size() - (j - 1 ); //The jth day will start at i but can end at i up till hw -1; hw = size of array - number of days left after today.
        int result = INF;
        for (int t = i; t < hw; t++) {
            int mx = 0;
            for (int left = i; left <= t; left++) {
                mx = max(mx, jd[left]);
            }
            int curr = mx + solve(t + 1, j - 1, jd);
            if (curr < result) {
                result = curr;
            }
        }
        return dp[i][j] = result;
    }


public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof dp);
        D = d;
        int ans = solve(0, d, jobDifficulty);
        if (ans == INF) return -1;
        return ans;
    }
};