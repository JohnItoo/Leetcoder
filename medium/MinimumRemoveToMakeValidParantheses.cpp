class Solution {
public:
    string cleanCloseAtBeginOpenAtEnd(string s) {
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == ')') {
            i++;
        }
        
        int j = n-1;
        while(j >= 0 && s[j] == '(' ) {
            j--;
        }
        string res;
        if(i < n) {
            res = s.substr(i, j-i+1);
        }

        return res;
        
    }
    string minRemoveToMakeValid(string s) {
        int val = 0;
        unordered_set<int> bad;
        
        
        s =  cleanCloseAtBeginOpenAtEnd(s);
        int n = s.size();

        
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
       string res = "";
        
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') {
                if(val) val--; // clean extra '(' from the back.
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