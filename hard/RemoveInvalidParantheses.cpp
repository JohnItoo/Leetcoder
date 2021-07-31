class Solution {
public:
    int longestLength = -1;

    void backtrack(int i, string& s, string curr, map<int, set<string> >& lenMap, int n, 
                  int open , int close) {
        
        if(i == n) {
            if(open != close) return;
            int currLength = curr.length();
            longestLength = max(longestLength, currLength);
            lenMap[currLength].insert(curr);
            return;
        }
        if(s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            backtrack(i+1, s, curr,lenMap, n, open, close);
        } else {
             backtrack(i+1, s, curr, lenMap, n, open, close);
             curr.push_back(s[i]);
            if(s[i] == '(' || (s[i] == ')' && open > close)) {
                 bool isOpen = s[i] == '(';
                 backtrack(i+1, s, curr, lenMap, n, open + isOpen, close + (!isOpen));
                 curr.pop_back();
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        map<int, set<string> > lenMap;
        int open = 0, close = 0;
        string curr;
        backtrack(0, s, curr , lenMap, n, open, close);
    
        set<string> resset = lenMap[longestLength];
        vector<string> ans;

        
        for(string curr: resset) ans.push_back(curr);
        return ans;
    }
};