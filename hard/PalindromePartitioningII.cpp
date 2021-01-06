class Solution {
   public:
    int memoize(int j, vector<vector<bool>> &palindrome, vector<int> &dp) {
        if (j > dp.size() - 1) return -1;

        if (dp[j] != -1) return dp[j];
        dp[j] = dp.size() - 1;
        for (int end = 1; end < dp.size(); end++) {
            if (!palindrome[j][end]) continue;
            int compute = memoize(end + 1, palindrome, dp);
            dp[j] = min(dp[j], compute + 1);
        }

        return dp[j];
    }

    int iterative(vector<vector<bool>> &palindrome, vector<int> &dp) {
        // palindrome ends at i;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j <= i; j++) {
                if (palindrome[j][i]) {
                    dp[i] = min(dp[j - 1] + 1, dp[i]);
                }
            }
        }

        return dp[dp.size() - 1];
    }

    int minCut(string s) {
        int INF = 1e9 + 8;
        vector<int> dpr(s.length() + 1, -1);       // recursive
        vector<int> dpi(s.length() + 1, INT_MAX);  // iterative
        vector<vector<bool>> palindrome(s.length() + 1,
                                        vector<bool>(s.length() + 1, false));
        for (int i = 1; i <= s.length(); i++) {
            int len = 1;
            palindrome[i][i] = true;
            while (i - len >= 1 && i + len <= s.length() &&
                   s[i - len - 1] == s[i + len - 1]) {
                palindrome[i - len][i + len] = true;
                len++;
            }
            int p = i;
            int q = i + 1;
            while (p >= 1 && q <= s.length() && s[p - 1] == s[q - 1]) {
                palindrome[p][q] = true;
                p--;
                q++;
            }
        }
        dpi[0] = -1;
        dpi[1] = 0;
        // return memoize(1, palindrome, dpr);
        return iterative(palindrome, dpi);
    }
};