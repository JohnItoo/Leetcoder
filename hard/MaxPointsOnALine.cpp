class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (points.size() == 0) return 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dy = y2 - y1;
                int dx = x2 - x1;
                int gcd = __gcd(dy, dx);
                dy /= gcd;
                dx /= gcd;
                mp[{dy, dx}]++;
                ans = max(ans, mp[{dy, dx}] + 1);
            }
        }
        return ans;
    }
};