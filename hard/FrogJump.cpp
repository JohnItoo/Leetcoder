class Solution {
    using ll = long long;
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool> > dp(n, vector<bool>(2005));
        if(stones[1] != 1) return false;
        dp[1][1] = true;
        unordered_map<ll, int> mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i] * 1LL] = i;
        }
        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j <= 2000; j++) {
                if(!dp[i][j]) continue;
                for(int k = j-1; k <= j+1; k++) {
                    if(k == 0) continue;
                    ll newPosition = stones[i]+ k;
                    if(mp.find(newPosition) != mp.end()) {
                        int newPosIdx = mp[newPosition];
                        dp[newPosIdx][k] = true;
                    }
                }
            }       
        }
        int ans = false;
        for(int j = 1; j <= 2000; j++) {
            ans |= dp[n-1][j];
        }
        return ans;
    }
};