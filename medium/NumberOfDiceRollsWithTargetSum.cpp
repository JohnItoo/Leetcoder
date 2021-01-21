class Solution {
   public:
    int numRollsToTarget(int d, int f, int target) {
        int mod = 1e9 + 7;

        vector<vector<int> > dp(d + 5, vector<int>(target + 5, 0));
        dp[0][0] = 1;
        for (int dice = 1; dice <= d; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int face = 1; face <= f; face++) {
                    if (face > sum) break;
                    dp[dice][sum] += dp[dice - 1][sum - face];
                    dp[dice][sum] %= mod;
                }
            }
        }
        return dp[d][target];
    }
};