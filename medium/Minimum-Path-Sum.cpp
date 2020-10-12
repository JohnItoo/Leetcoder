class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 100000));

        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                dp[row][col] =
                    min(
                        (row <= 1 ? 10000000 : dp[row - 1][col]),
                        (col <= 1 && row <= 1 ? 0 : dp[row][col - 1])
                    ) + grid[row - 1][col - 1];
                cout << dp[row][col] << " ";
            }
            cout << "\n";
        }

        return dp[rows][cols];




    }
};