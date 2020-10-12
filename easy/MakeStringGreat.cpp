//Question 1544 
class Solution {

public: int isGood(string s) {
        bool is = true;
        int st = -1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (s[i] - 'a' == s[i + 1] - 'A') {
                    is = false;
                    st = i;
                    break;
                }
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[i] - 'A' == s[i + 1] - 'a') {
                    is = false;
                    st = i;
                    break;
                }
            }
        }
        return st;
    }
public:
    string makeGood(string s) {
        int isIt = isGood(s);
        while (isIt != -1 && s.length() > 2) {
            int len = s.length();
            string nw = s.substr(0, isIt);
            string nq = s.substr(isIt + 2, len - (isIt + 2));
            s = nw + nq;
            isIt = isGood(s);
        }
        if (isGood(s) != -1) return "";
        else return s;
    }
};