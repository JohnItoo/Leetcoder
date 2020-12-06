class Solution {

public:
    bool isValidWord(string s) {
        if (s == "") return false;
        if (s == " ") return false;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (!(s[i] >= 'a' && s[i] <= 'z')) return false;
        }
        return true;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        map<string, int> words;
        map<string, int> bannedMap;
        for (string word : banned) bannedMap[word]++;
        int n = paragraph.length();
        int last = 0;
        int i = 0;
        while (i < n && last < n) {
            if (!(paragraph[i] >= 'a' && paragraph[i] <= 'z')) {
                string sub = paragraph.substr(last, i - last);
                if (isValidWord(sub)) {
                    words[sub]++;
                }
                i++;
                last = i;
            } else {
                i++;
            }
        }
        string sub = paragraph.substr(last, n - last);
        if (isValidWord(sub)) words[sub]++;

        int mx = 0;
        string ans = "";
        for (auto ii : words) {
            cout << ii.first << " " << ii.second << " " << mx << endl;
            if (ii.second > mx && bannedMap.find(ii.first) == bannedMap.end()) {
                mx = ii.second;
                ans = ii.first;
                cout << ans << "set ans\n";
            }
        }
        return ans;
    }
};