class Solution {
   public:
    bool halvesAreAlike(string s) {
        unordered_map<char, int> vowels;
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = 1;
        vowels['A'] = vowels['E'] = vowels['I'] = vowels['O'] = vowels['U'] = 1;
        int n = s.length();
        int left = 0, right = 0, i = 0, j = n - 1;
        while (i < j) {
            if (vowels.count(s[i++])) left++;
            if (vowels.count(s[j--])) right++;
        }
        return left == right;
    }
};