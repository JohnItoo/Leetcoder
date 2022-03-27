class Solution {
    using ll = long long;
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) { // 0-1 knapsack. You can either pick from one pile or you don't
      int n = piles.size();

      vector<vector<ll> > dp(n+5, vector<ll>(k+5));

        
      for(int i = 0; i <= k; i++) {
          dp[0][i] = 0;
      }
        
     for(int p = 1; p <= n; p++) { // using the first p piles
         int pile = p-1;
         for(int K = 1; K <= k; K++) { // select K coins 
             ll pref = 0LL;
             for(int j = 0; j <= piles[pile].size() && j <= K; j++) { // pick j elements from this pile
                if(j > 0) {
                    pref += ( piles[pile][j-1] * 1LL);
                }
                dp[p][K] = max(dp[p][K], dp[p-1][K-j]  + (j > 0 ? pref : 0));
             }
         }
     }
    
    return dp[n][k];
   
        
    }
};