class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        int n = s.length();
        for (int i = 0; i + 10 <= n; i++) {
            string sub = s.substr(i, 10);
            mp[sub]++;
        }
        vector<string> result;
        for (auto el : mp) {
            if (el.second > 1) {
                result.push_back(el.first);
            }
        }
        return result;
    }
};