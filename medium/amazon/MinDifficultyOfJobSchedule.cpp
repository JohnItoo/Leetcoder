class Solution
{
public:
    int dp[315][15];
    int INF = 1e9 + 8;

    int solve(int index, int remDays, vector<int> &jd)
    {

        int n = jd.size();
        if (index == n && remDays == 0)
        {
            return 0;
        }
        if (index == n || remDays == 0 || remDays > n - index)
        {
            return INF;
        }
        if (dp[index][remDays] != -1)
        {
            return dp[index][remDays];
        }
        dp[index][remDays] = INF;
        int mx = 0;
        for (int ct = index; ct < n; ct++)
        {                         // the cth job can still be done on currentDay;
            mx = max(mx, jd[ct]); // max from obvious start index till point ct;
            dp[index][remDays] = min(dp[index][remDays], solve(ct + 1, remDays - 1, jd) + mx);
        }
        return dp[index][remDays];
    }

    int minDifficulty(vector<int> &jd, int d)
    {
        int n = jd.size();
        memset(dp, -1, sizeof dp);
        int res = solve(0, d, jd);
        if (res == INF)
            return -1;
        return res;
    }
};