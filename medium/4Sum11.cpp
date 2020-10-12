//TLE on Second to tbe Last testcase

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if (n == 0) return n;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());

        set<tuple<int, int, int> > sta;
        set<tuple<int, int, int> > stb;
        set<int> st;

        int ct = 0;
        int xx = -1;

        while ( xx + 1 < n && A[xx + 1] == 0 && B[xx + 1] == 0 && C[xx + 1] == 0 && D[xx + 1] == 0) {
            xx++;
        }
        ct = xx + 1;
        for (int i = xx + 1; i < n; i++) {
            for (int j = xx + 1; j < n; j++) {
                int smx = A[i] + B[j];
                int smy = C[i] + D[j];
                st.insert(smx);
                st.insert(smy);
                sta.emplace(smx, i, j);
                stb.emplace(smy, i, j);
            }
        }
        int ans = 0;
        int q = 0;
        ans = ct * ct * ct * ct;
        while (!sta.empty()) {
            tuple<int, int, int> curra = *sta.begin();
            int frst = get<0>(curra);
            tuple<int, int, int> fnd = make_tuple(-frst, -1, -1);
            sta.erase(sta.begin());

            auto it = stb.lower_bound(fnd);

            while (it != stb.end()) {
                tuple<int, int, int> currb = *it;
                if (get<0>(currb) != -frst) break;
                ans++;
                ++it;

            }
            q++;
        }

        return ans;

    }
};

//Simple O(N^2) with maps.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        for (auto a : A) {
            for (auto b : B) {
                mp[a + b]++;
            }
        }
        int ans = 0;
        for (auto a : C) {
            for (auto b : D) {
                auto it = mp.find(-(a + b));
                if (it != mp.end()) {
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};