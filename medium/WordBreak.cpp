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
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> dictionary;

        int n = wordDict.size();
        for (int i = 0; i < n; i++) {
            dictionary[wordDict[i]] = 1;
        }
        return check(s, dictionary);
    }
};

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, int> mp;
        int m = wordDict.size();
        for (int i = 0; i < m; i++) {
            mp[wordDict[i]] = 1;
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // if it ended at dp[i] is it valid.
        // At each point what is important.
        // first char is at index 1 so if we end at index 0 it is valid.
        // For all true positions before current position. Since validity ends
        // at where it is "true". check if a word can be formed from immediately
        // after that "true" to include my current position.

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j]) continue;
                string sub = s.substr(j, i - j);
                if (mp.count(sub)) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};