//THIS PROBLEM on Leetcode is https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

#include <bits/stdc++.h>
using namespace std;
int D = 0;
vector<int> difc;
int INF = 1e9 + 7;
int dp[305][15];


int solve(int i , int j) {
    if (j == 1) {
        int lft = i;
        int mx = 0;
        while (lft < difc.size()) mx = max(mx, difc[lft++]);
        return mx;
    }
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = INF;
    int hw = difc.size() - (j - 1); // we can take all jobs from i to hw-1 on  this day j
    int result = INF;
    int mx = difc[i];
    for (int t = i; t < hw; t++) {
        mx = max(mx, difc[t]);
        // cout << mx << " " << j << endl;
        int curr = mx + solve(t + 1, j - 1); // the next guy starts at t+1, a
        if (curr < result) {
            // cout << t << " t : curr " << j << " " << curr << endl;
            result = curr;
        }
    }

    return dp[i][j] = result;
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        difc.push_back(x);
    }
    cin >> D;
    int ans = solve(0, D);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
