class Solution {
   public:
    unordered_map<string, bool> mp;
    bool check(string s, map<string, int> dictionary) {
        int n = s.length();
        if (mp.find(s) != mp.end()) return mp[s];
        for (int i = 1; i <= n; i++) {
            string prefix = s.substr(0, i);
            string suffix = s.substr(i, n - i);
            if (dictionary.find(prefix) == dictionary.end()) continue;
            mp[prefix] = 1;
            if (suffix.length() == 0) return true;
            if (check(suffix, dictionary)) {
                mp[suffix] = 1;
                return true;
            }
        }
        mp[s] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict) {
        map<string, int> dictionary;

        int n = wordDict.size();
        for (int i = 0; i < n; i++) {
            dictionary[wordDict[i]] = 1;
        }
        return check(s, dictionary);
    }
};