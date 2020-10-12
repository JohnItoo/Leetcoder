class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        set<int> rows;
        set<int> cols;
        int m = matrix.size();
        if (m == 0) return;

        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        auto it = rows.begin();
        while (it != rows.end()) {
            int row = *it;
            for (int i = 0; i < n; i++) {
                matrix[row][i] = 0;
            }
            ++it;
        }

        it = cols.begin();
        while (it != cols.end()) {
            int col = *it;
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
            ++it;
        }
    }
};