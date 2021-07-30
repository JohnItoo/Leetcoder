class Solution {
public:
    bool divideConquer(string& s, int i , int j) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        bool canIgnore = true;
        int i = 0;
        int j = n-1;
        pair<int, int> mv;
        int desc;
        bool fd = true;
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else if(canIgnore) {
                canIgnore = false;
                if(s[i+1] == s[j] || s[i] == s[j-1]) {
                  return divideConquer(s, i+1, j) || 
                       divideConquer(s, i, j-1);
                }
            } else {
                return false;
            }
        }
       
        return true;
    }
};