class Solution {
   public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mp;

        for (string path : paths) {
            int i = 0;
            int n = path.size();
            while (path[i] != ' ') i++;

            string base = path.substr(0, i);
            i++;

            while (i < n) {
                int begin = i, left = 0, right = 0;
                while (i < n && path[i] != ' ') {
                    if (path[i] == '(') left = i;
                    if (path[i] == ')') right = i;
                    i++;
                }
                string filename = path.substr(begin, left - begin);
                string content = path.substr(left + 1, right - left - 1);
                mp[content].push_back(base + "/" + filename);
                i++;
            }
        }
        vector<vector<string>> result;
        for (auto it : mp) {
            if (it.second.size() < 2) continue;

            result.push_back(it.second);
        }

        return result;
    }
};