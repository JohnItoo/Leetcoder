class Solution {
   public:
    int dp[315][15];
    int INF = 1e9 + 8;

    int solve(int index, int remDays, vector<int> &jd) {
        int n = jd.size();
        if (index == n && remDays == 0) {
            return 0;
        }
        if (index == n || remDays == 0 || remDays > n - index) {
            return INF;
        }
        if (dp[index][remDays] != -1) {
            return dp[index][remDays];
        }
        dp[index][remDays] = INF;
        int mx = 0;
        for (int ct = index; ct < n;
             ct++) {  // the cth job can still be done on currentDay;
            mx =
                max(mx, jd[ct]);  // max from obvious start index till point ct;
            dp[index][remDays] =
                min(dp[index][remDays], solve(ct + 1, remDays - 1, jd) + mx);
        }
        return dp[index][remDays];
    }

    int minDifficulty(vector<int> &jd, int d) {
        int n = jd.size();
        memset(dp, -1, sizeof dp);
        int res = solve(0, d, jd);
        if (res == INF) return -1;
        return res;
    }
};

// bottom up
#define INF 1000000
class Solution {
   public:
    int minDifficulty(vector<int> &jd, int D) {
        int n = jd.size();
        vector<vector<int> > dp(n + 5, vector<int>(D + 5, INF));

        dp[0][0] = 0;

        // The jth job is the last job on the d day.
        for (int j = 1; j <= n; j++) {
            for (int d = 1; d <= D; d++) {
                // for(int k = d; k <=j; k++) { // k signifies all positions
                // where the jobs for the dth day can start from and ofcourse
                // end at j
                // We can keep a ranges array where we know max from k to j
                //     int mxrange = range[min(k,j)][max(k,j)];
                //     dp[j][d] = min(dp[j][d], dp[k-1][d-1] + mxrange);
                // }
                // or we can go from behind and keep track of the max.
                int mx = jd[j - 1];
                for (int k = j; k >= d; k--) {
                    mx = max(mx, jd[k - 1]);
                    dp[j][d] = min(dp[j][d], dp[k - 1][d - 1] + mx);
                }
            }
        }

        if (dp[n][D] == INF) return -1;
        return dp[n][D];
    }
};