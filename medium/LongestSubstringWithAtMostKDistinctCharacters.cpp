class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> fq;
        int i = 0;
        int j = 0;
        int n = s.size();
        int mx = 0;
        while (j < n) {
            while (j < n && fq.size() <= k) {
                mx = max(mx, j - i);
                fq[s[j++]]++;
            }
            while (i < j && fq.size() > k) {
                if (fq[s[i]] == 1) {
                    fq.erase(s[i++]);
                } else {
                    fq[s[i++]]--;
                }
            }
        }
        mx = max(mx, j - i);
        return mx;
    }
};