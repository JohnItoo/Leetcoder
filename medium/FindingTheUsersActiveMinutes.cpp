class Solution {
   public:
    static bool comp(pair<int, int> x, pair<int, int> y) {
        if (abs(x.first - x.second) == abs(y.first - y.second))
            return x.first < y.first;
        return abs(x.first - x.second) < abs(y.first - y.second);
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int> > vpp;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            vpp.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(vpp.begin(), vpp.end(), comp);
        int mod = 1e9 + 7;
        int pref = 0;
        for (int i = 0; i < n - 1; i++) {
            pref += abs(vpp[i].first - vpp[i].second);
            pref %= mod;
        }
        int mn = mod;
        for (int i = 0; i < n; i++) {
            mn = min(mn, abs(vpp[i].first - vpp[n - 1].second));
        }
        int ans = pref + mn;
        ans %= mod;
        return ans;
    }
};