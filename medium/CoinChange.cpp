class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int mx = 1e7;
        vector<int> dp(1e4+5, mx);
        dp[0] = 0;
        for(int i =1; i < 1e4+5; i++) {
            for(auto& coin : coins) {
                if(coin > i) continue;
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        if(dp[amount] >= mx) return -1;
        return dp[amount];
    }
};