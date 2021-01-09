#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<vector<int> > dp(n+5, vector<int>(k+5, 0));
    dp[1][0] = 1;
    dp[2][1] = 1;

    for(int step = 3; step <= n; step++) {
        for(int jump = 1; jump <= k; jump++) {
            dp[step][jump] += dp[step-1][jump-1] + dp[step-2][jump-1];
    
        }
    }
    for(int jump = 0; jump <= k; jump++) {
        cout << dp[5][jump] << " ";
    }
    cout << endl;


    return 0;
}