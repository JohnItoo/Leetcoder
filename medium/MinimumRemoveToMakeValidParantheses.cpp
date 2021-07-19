class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int val = 0;
        unordered_set<int> bad;
        
        
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ')') break;
            if(s[i] == '(') {
                bad.insert(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') break;
            if(s[i] == ')') {
                bad.insert(i);
            }
        }
        
        
        
        string res;
        
        for(int i = 0; i < n; i++) {
            if(s[i] != ')' && s[i] != '(') {
                res.push_back(s[i]);
            } else {
                if(bad.find(i) == bad.end()){
                        res.push_back(s[i]);
               }
            }
        }
        
        
        s = res;
        n = res.size();
        bad.clear();

        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                val++;
            } else if(s[i] == ')') {
                if(val == 0) {
                    bad.insert(i);
                } else {
                    val--;
                }
            }
        }
        res = "";
        
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') {
                if(val) val--;
                else{
                    res.push_back(s[i]);
                }
            } else{
                if(bad.find(i) == bad.end()) {
                    res.push_back(s[i]);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};