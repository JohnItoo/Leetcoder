class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s == t) return false;
        int n = s.size();
        int m = t.size();
        if(n == m) {
            for(int i = 0; i < n; i++) {
                string lefts = s.substr(0, i);
                string leftt = t.substr(0, i);
                string rights = s.substr(i+1, n-i);
                string rightt = t.substr(i+1, n-i);
                if(lefts == leftt && rights == rightt) return true;
            }
        
        } else if(n-m == 1) {
            for(int i = 0; i < n; i++) {
                 string lefts = s.substr(0, i);
                string rights = s.substr(i+1, n-i);
                if(lefts + rights == t) return true;
            }
        } else if(m - n == 1) {
             for(int i = 0; i < m; i++) {
                 string leftt = t.substr(0, i);
                string rightt = t.substr(i+1, m-i);
                if(leftt + rightt == s) return true;
            }
        }
        return false;
    }
};