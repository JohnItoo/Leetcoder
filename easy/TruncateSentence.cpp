class Solution {
   public:
    string truncateSentence(string s, int k) {
        string res = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            res.push_back(s[i]);
            if (s[i] == ' ') {
                k--;
            }
            if (k == 0) break;
        }
        if (res[res.length() - 1] == ' ') res.pop_back();
        return res;
    }
};