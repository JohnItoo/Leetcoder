class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return s;

        string left = string(1, s[0]);
        string right;
        char temp;
        int idx = 0;
        for(int i = 1; i < n; i++) {
            right.push_back(s[i]);
            if(right.size() > left.size()) {
                temp = right[0];
                right = right.substr(1, right.size()-1);
            }
            if(right == left) {
                idx = i;
            }
            if(temp != '*') {
                left.insert(0, 1, temp);
                temp = '*';
            }
        }
        string stub = s.substr(idx+1, n-idx-1);
        reverse(stub.begin(), stub.end());
        string ans = stub + s;
        return ans;
    }
};