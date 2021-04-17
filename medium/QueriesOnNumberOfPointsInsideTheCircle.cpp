class Solution {
   public:
    vector<int> countPoints(vector<vector<int>>& points,
                            vector<vector<int>>& queries) {
        int n = points.size();
        int m = queries.size();
        vector<int> res;
        for (int i = 0; i < m; i++) {
            int xc = queries[i][0];
            int yc = queries[i][1];
            int r = queries[i][2];
            int ans = 0;
            for (int j = 0; j < n; j++) {
                int xp = points[j][0];
                int yp = points[j][1];
                if ((((xp - xc) * (xp - xc)) + ((yp - yc) * (yp - yc))) <=
                    r * r) {
                    ans++;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};