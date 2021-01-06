class Solution {
   public:
    void isPalindrome(vector<string>& curr, string s, int i,
                      vector<vector<string>>& result,
                      vector<vector<bool>>& isV) {
        int n = s.length();
        if (i >= n) {
            result.push_back(curr);
            return;
        }
        for (int idx = i; idx < n; idx++) {
            if (!isV[i][idx]) continue;
            string nw = s.substr(i, (idx - i) + 1);
            curr.push_back(nw);
            isPalindrome(curr, s, idx + 1, result, isV);
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        vector<vector<bool>> isV(s.length(), vector<bool>(s.length(), false));
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int len = 0;
            while (i - len >= 0 && i + len < n && s[i - len] == s[i + len]) {
                isV[i - len][i + len] = 1;
                len++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) continue;
            isV[i][i + 1] = 1;
            int len = 1;
            while (i - len >= 0 && i + 1 + len < n &&
                   s[i - len] == s[i + 1 + len]) {
                isV[i - len][i + 1 + len] = 1;
                len++;
            }
        }

        isPalindrome(curr, s, 0, result, isV);
        return result;
    }
};