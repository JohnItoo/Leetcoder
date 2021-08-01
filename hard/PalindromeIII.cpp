class Solution {
public:
    int isValid(string& s, int l, int r, vector<vector<int> >& mem) {
        if(l >= r) return 0;
        if(mem[l][r] != 1e9) {
            return mem[l][r];
        }
         
        if(s[l] == s[r]) {
            return isValid(s, l+1, r-1, mem);
        }
        int deleteToMakePal =  min(isValid(s, l, r-1, mem), isValid(s, l+1, r, mem)) + 1; 

       mem[l][r] = deleteToMakePal;
    return deleteToMakePal;
        
    }
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int> > mem(n, vector<int>(n, 1e9));
        
        int val = isValid(s,  0, n-1, mem);
        return val <= k;
    }
};