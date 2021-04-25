class Solution {
   public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int i = 0;
        int j = 0;
        int mn = 0;
        int ans = 0;
        map<char, int> mp;
        mp['a'] = 1;
        mp['e'] = 2;
        mp['i'] = 3;
        mp['o'] = 4;
        mp['u'] = 5;
        set<char> st;
        while (j < n) {
            if (mp[word[j]] < mn) {
                if (st.size() == 5) ans = max(ans, j - i);
                st.clear();
                i = j;
                mn = mp[word[j]];
            } else {
                mn = mp[word[j]];
                st.insert(word[j]);
                j++;
            }
        }
        if (st.size() == 5) ans = max(ans, j - i);
        return ans;
    }
};