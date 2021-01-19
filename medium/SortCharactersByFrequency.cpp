class Solution {
   public:
    static bool comp(pair<int, char> a, pair<int, char> b) {
        return a.first > b.first;
    }
    string frequencySort(string s) {
        map<char, int> mp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        vector<pair<int, char> > vpp;
        for (auto el : mp) {
            vpp.push_back(make_pair(el.second, el.first));
        }
        sort(vpp.begin(), vpp.end(), comp);
        int m = vpp.size();
        string ans = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < vpp[i].first; j++) {
                ans.push_back(vpp[i].second);
            }
        }
        return ans;
    }
};