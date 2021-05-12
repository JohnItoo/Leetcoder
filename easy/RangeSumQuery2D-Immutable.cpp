class NumMatrix {
   public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] +
                             matrix[i - 1][j - 1] - pref[i - 1][j - 1];
            }
        }
        prefix = pref;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 += 1;
        col1 += 1;
        row2 += 1;
        col2 += 1;
        int A = prefix[row2][col2];
        int B = prefix[row2][col1 - 1];
        int D = prefix[row1 - 1][col1 - 1];
        int C = prefix[row1 - 1][col2];
        return A - C - B + D;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */