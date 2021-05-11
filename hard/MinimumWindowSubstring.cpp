class Solution {
    // 2POINTERS O(N).
   public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> freq;
        unordered_map<char, int> tfreq;
        for (int i = 0; i < m; i++) {
            tfreq[t[i]]++;
        }
        int curr = 0;
        int i = 0, j = 0;
        int left = -1;
        int right = -1;

        while (j < n) {
            while (curr < m && j < n) {
                if (tfreq.count(s[j])) {
                    freq[s[j]]++;
                    if (freq[s[j]] <= tfreq[s[j]]) curr++;
                }
                j++;
            }
            if (curr == m && (left == -1 || (j - i - 1 < right - left))) {
                right = j - 1;
                left = i;
            }
            while (curr == m && i <= j) {
                if (tfreq.count(s[i])) {
                    freq[s[i]]--;
                    if (freq[s[i]] < tfreq[s[i]]) curr--;
                }
                i++;
            }
            if ((left == -1 || (j - i < right - left))) {
                right = j - 1;
                left = i - 1;
            }
        }
        if (left == -1)
            return "";
        else
            return s.substr(left, (right - left + 1));
    }
};