class Solution {
    using ll = long long;
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int mx = INT_MAX;
        vector<vector<ll> > dp(n+5, vector<ll>(m+5, mx));
        dp[0][0] = 0;
        
        vector<ll> pref(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            pref[i] = (nums[i-1] + pref[i-1]) * 1LL;
        }
        
        for(int i = 1; i <= n; i++) {
            dp[i][0] = mx;
        }
        for(int i = 1; i <= m; i++){
            dp[0][i] = mx;
        }
        
        for(int i = 1; i <= n; i++) { // first i
            for(int j = 1; j <= m; j++) { // j divisions
                if(j > i) break;
                ll ans = 0;
                for(int k = j-1; k < i; k++) { //previs division ends here @ k
                   ll here = max(dp[k][j-1], pref[i] - pref[k]);
                   dp[i][j] = min(dp[i][j], here);
                }
            }
        }
        return dp[n][m];
       
    }
};