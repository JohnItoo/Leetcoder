class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<map<int, int>> prefs(n);


        int m = preferences[0].size();

        map<int, int> prs;
        for (vector<int> pr : pairs) {
            prs[pr[0]] = pr[1];
            prs[pr[1]] = pr[0];
        }

        for (int i = 0;  i < n; i++) {
            map<int, int> curr;
            vector<int> cp = preferences[i];
            for (int j = 0; j < m; j++) {
                curr[cp[j]] = j;
            }
            prefs[i] = curr;
        }
        int ans = 0;
        for (vector<int> pr : pairs) {
            int x = pr[0];
            int y = pr[1];
            vector<int> preflst = preferences[x];
            vector<int> preflsty = preferences[y];
            int i = 0;

            while (preflst[i] != y) {
                int des = preflst[i];
                map<int, int> otherlst = prefs[des];
                int despair = prs[des];
                if (otherlst[despair] > otherlst[x]) {
                    ans++;
                    break;
                }
                i++;
            }
            i = 0;
            while (preflsty[i] != x) {
                int desire = preflsty[i];
                map<int, int> desiresmp = prefs[desire];
                int desirepair = prs[desire];
                if (desiresmp[desirepair] > desiresmp[y]) {
                    ans++;
                    break;
                }
                i++;
            }

        }
        return ans;

    }
};