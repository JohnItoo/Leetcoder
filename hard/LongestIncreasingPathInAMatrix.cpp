class Solution {
   public:
    int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int recurse(vector<vector<int>>& matrix, int i, int j,
                map<pair<int, int>, int>& mp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m) return -1;

        if (mp.count({i, j})) {
            return mp[{i, j}];
        }
        bool valid = false;
        stack<pair<int, int>> st;
        for (int k = 0; k < 4; k++) {
            int ni = i + arr[k][0];
            int nj = j + arr[k][1];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (matrix[ni][nj] < matrix[i][j]) {
                st.push({ni, nj});
            }
        }

        if (st.empty()) {
            mp[{i, j}] = 1;
            return 1;
        }
        int ans = 0;
        while (!st.empty()) {  // not a single neighbour is less than it and
                               // stack will be empty. if at least one is less
                               // than it stack will contain
            pair<int, int> tp = st.top();
            st.pop();
            ans = max(ans, recurse(matrix, tp.first, tp.second, mp));
        }
        ans += 1;
        mp[{i, j}] = ans;

        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<pair<int, int>, int> mp;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool valid = false;
                for (int k = 0; k < 4; k++) {
                    int ni = i + arr[k][0];
                    int nj = j + arr[k][1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    valid |= matrix[ni][nj] <
                             matrix[i][j];  // true if at least one neighbour is
                                            // less than it
                }
                if (!valid) continue;
                cout << i << " " << j << endl;
                ans = max(ans, recurse(matrix, i, j, mp));
                // cout << ans << endl;
            }
        }
        return ans;
    }
};