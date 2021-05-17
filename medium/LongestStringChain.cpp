class Solution {
   public:
    static bool sortStringByLength(string a, string b) {
        if (a.length() == b.length()) return a < b;
        return (a.length() < b.length());
    }
    bool can(string longer, string shorter) {
        if (longer.length() != shorter.length() + 1) return false;
        for (int i = 0; i < longer.length(); i++) {
            string left = longer.substr(0, i);
            string right = longer.substr(i + 1, longer.length() - i - 1);
            if (left + right == shorter) return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), sortStringByLength);
        int n = words.size();
        vector<int> maxHere(n, 0);
        maxHere[0] = 1;
        int res = 1;
        for (int i = 1; i < n; i++) {
            maxHere[i] = 1;
            res = max(res, maxHere[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (words[i].length() == words[j].length()) continue;
                if (can(words[i], words[j])) {
                    maxHere[i] = max(maxHere[j] + 1, maxHere[i]);
                    res = max(res, maxHere[i]);
                }
                if (words[i].length() - words[j].length() >= 2) break;
            }
        }
        return res;
    }
};