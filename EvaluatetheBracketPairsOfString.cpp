class Solution {
   public:
    string evaluate(string s, vector<vector<string>>& k) {
        map<string, string> mp;
        int n = k.size();
        for (int i = 0; i < n; i++) {
            mp[k[i][0]] = k[i][1];
        }
        int i = 0;
        int j = 0;
        bool in = false;
        int len = s.length();
        string res = "";
        while (j < len) {
            if (s[j] != '(' && s[j] != ')') {
                if (in) {
                    j++;
                } else {
                    res.push_back(s[j]);
                    j++;
                }
                continue;
            }
            if (s[j] == '(') {
                in = true;
                i = j;
                j++;
            } else if (s[j] == ')') {
                in = false;
                string key = s.substr(i + 1, j - i - 1);
                if (mp.count(key)) {
                    res += mp[key];
                } else {
                    string add = "?";
                    res += add;
                }
                j++;
            }
        }
        return res;
    }
};