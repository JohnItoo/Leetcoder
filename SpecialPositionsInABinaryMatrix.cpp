class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        vector<pair<int, int>> spe;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (mat[i][j] == 1) spe.push_back(make_pair(i, j));
            }
        }
        int ans = 0;
        for (pair<int, int> ca : spe) {
            bool is = true;

            for (int j = 0; j < m; j++) {
                if (mat[ca.first][j] == 1 && j != ca.second) {
                    is = false;
                    break;
                }
            }

            for (int i = 0; i < n; i++) {
                if (mat[i][ca.second] == 1 && i != ca.first) {
                    is = false;
                    break;
                }
            }
            if (is) ans++;

        }

        return ans;

    }
};