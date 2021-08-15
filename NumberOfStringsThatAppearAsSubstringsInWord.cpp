class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        multiset<string> pt; unordered_set<string> dn;
        for(string p: patterns) {
            pt.insert(p);
        }
        int n = word.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string sb = word.substr(i, j-i+1);
                dn.insert(sb);
            }
        }
        int ans = 0;
        for(string pp : pt) {
            if(dn.find(pp) != dn.end()) ans++;
        }
        return ans;
    }
};