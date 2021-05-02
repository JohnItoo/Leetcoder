class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i'  || c == 'e' || c == 
            'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = i;
        int curr = 0;
        int ans = 0;
        while(j < k) {
           if(isVowel(s[j++])) curr++; 
        }
        ans = max(curr, ans);
        while(i + k + 1 <= n) {
            if(isVowel(s[j++])) curr++;
            if(isVowel(s[i++])) curr--;
            ans = max(curr, ans);
        }
        ans = max(curr, ans);
        return ans;
    }
};