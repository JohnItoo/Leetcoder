class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0) return m;

        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        
        for(int row = 1; row <=m; row++) {
            for(int col = 1; col <= n; col++) {
                dp[row][col] = 
                    
                    (row <= 1 ? 0 : dp[row-1][col]) +
                    (col <= 1 && row <= 1 ? 0 : dp[row][col-1]) + dp[row][col];
            
                cout << dp[row][col] << " ";
            }
            cout << "\n";
        }
        
        return dp[m][n];
    }
};