class Solution {
   public:
    bool isPalindrome(string s) {
        string q = s;
        reverse(q.begin(), q.end());
        return q == s;
    }
    string breakPalindrome(string palindrome) {
        int size = palindrome.length();
        if (size <= 1) return "";
        int i = 0;
        while (i < size - 1) {
            if (palindrome[i] != 'a') {
                char temp = palindrome[i];
                palindrome[i] = 'a';
                if (!isPalindrome(palindrome)) {
                    return palindrome;
                }
                palindrome[i] = temp;
            }
            i++;
        }

        if (palindrome[size - 1] == 'a') {
            palindrome[size - 1] = 'b';
        } else {
            palindrome[size - 1] = 'a';
        }

        return palindrome;
    }
};