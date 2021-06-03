class Solution {
   public:
    int maxArea(int h, int w, vector<int>& horizon, vector<int>& vertical) {
        int n = horizon.size();
        int m = vertical.size();
        sort(horizon.begin(), horizon.end());
        sort(vertical.begin(), vertical.end());

        int left = 0;
        int mxh = 0;
        for (int i = 0; i < n; i++) {
            mxh = max(mxh, horizon[i] - left);
            left = horizon[i];
        }
        mxh = max(mxh, h - left);

        int mxv = 0;
        int up = 0;

        for (int i = 0; i < m; i++) {
            mxv = max(mxv, vertical[i] - up);
            up = vertical[i];
        }
        mxv = max(mxv, w - up);
        int md = 1e9 + 7;
        mxv %= md;
        mxh %= md;
        long long hr = (mxv * 1LL) * (mxh * 1LL);
        long long ans = hr % md;
        return ans;
    }
};