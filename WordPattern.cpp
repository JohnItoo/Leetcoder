class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mp;
        map<string, char> used;
        int last = 0;
        bool ans = true;
        int i = 0; int j = 0; int ct = 0;
        while(i < str.length() && j < str.length()) {
            while(j < str.length() && str[j] != ' ') {
                j++;
            }
            ct += 1;
            j += 1;
            i = j;
        }
        if(ct != pattern.length()) {
            return false;
        }
        for(int i = 0; i < pattern.length(); i++) {
            auto it = mp.find(pattern[i]);
            if(it == mp.end()) {
                string pres = "";
                while(last < str.length() && str[last] != ' ') {
                    pres.push_back(str[last++]);
                }
                last++;
                auto usedIt = used.find(pres);
                if(usedIt != used.end()) {
                    ans = (usedIt->second ==  pattern[i]);
                    if(!ans) break;
                   
                } else {
                  mp[pattern[i]] = pres;
                  used[pres] = pattern[i];
                }
              
            } else {
                string pres = "";
                while(last < str.length() && str[last] != ' ') {
                    pres.push_back(str[last++]);
                }
                last++;
                if(pres != it->second) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};