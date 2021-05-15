class Solution {
   public:
    string sortSentence(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        map<int, string> mp;

        while (i < n) {
            while (j < n && s[j] != ' ') {
                j++;
            }
            string hr = s.substr(i, j - i);
            int val = hr[j - i - 1] - '0';
            mp[val] = hr.substr(0, hr.length() - 1);
            j++;
            i = j;
        }
        string ans = "";
        for (auto ii : mp) {
            ans += ii.second;
            ans += " ";
        }
        ans = ans.substr(0, ans.length() - 1);
        return ans;
    }
};