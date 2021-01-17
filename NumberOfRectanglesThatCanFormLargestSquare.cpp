class Solution {
   public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, min(rectangles[i][0], rectangles[i][1]));
        }
        for (int i = 0; i < n; i++) {
            if (min(rectangles[i][0], rectangles[i][1]) >= mx) ans++;
        }
        return ans;
    }
};