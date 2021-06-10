class Solution {
    /**
      10 : 4
      8 : 2
      5 : 7
      3 : 3
      2 : 5
      1 : 9


    **/
#define MOD 1000000007
   public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector<pair<long long, long long> > vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({efficiency[i] * 1LL, speed[i] * 1LL});
        }
        sort(vp.rbegin(), vp.rend());

        vector<long long> sumbefore(n, 0);

        multiset<int> st;

        int md = 1e9 + 7;
        long long sm = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            sm += vp[i].second;
            ans = max(ans, sm * vp[i].first);
            st.insert(vp[i].second);
            if (st.size() > k - 1) {
                sm -= (*st.begin());
                st.erase(st.begin());
            }
        }

        return (int)(ans % MOD);
    }
};