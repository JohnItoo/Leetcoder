class Solution {
public:
    int toInt(char c) {
        int x =  c - '0';
        return x;
    }
    string replaceDigits(string s) {
      int n = s.length();
        for(int i = 1; i < n; i+=2) {
            s[i] = s[i-1] + toInt(s[i]);
        }
        return s;
    }
};