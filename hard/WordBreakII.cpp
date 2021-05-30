class Solution {
   public:
    vector<string> search(int i, string s, map<string, int> dict,
                          map<int, bool> can, map<int, vector<string> > mem) {
        if (i == s.size()) {
            return vector<string>(0);
        }
        vector<string> curr;
        bool fd = false;
        if (can.find(i) != can.end()) {
            if (can[i]) {
                return mem[i];
            } else {
                return vector<string>(1, "-1");
            }
        }
        int n = s.size();
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            if (dict.count(sub)) {
                vector<string> nw = search(j + 1, s, dict, can, mem);
                if (nw.size() == 1 && nw[0] == "-1") {
                    continue;
                }
                fd = true;

                if (nw.size() == 0) {
                    curr.push_back(sub);
                    continue;
                }
                for (string st : nw) {
                    curr.push_back(sub + " " + st);
                }
            }
        }
        if (!fd) {
            curr.push_back("-1");
            can[i] = false;
        } else {
            can[i] = true;
            mem[i] = curr;
        }
        return curr;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<int, bool> can;
        map<int, vector<string> > mem;
        map<string, int> dict;
        for (string word : wordDict) {
            dict[word] = 1;
        }
        vector<string> ans = search(0, s, dict, can, mem);
        if (ans.size() == 1 && ans[0] == "-1") {
            return vector<string>(0);
        }

        return ans;
    }
};