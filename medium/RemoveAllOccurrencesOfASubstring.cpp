class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0;
        
        while(i < s.size()) {
            if(s[i] != part[0]) i++;
            int is = i;
            int ip = 0;
            while(ip < part.size() && is < s.size() && s[is]== part[ip]) {
                ip++;
                is++;
            }
            if(ip ==part.size()) {
                string left = s.substr(0, i);
                int newIdx = i+part.size();
                int n = s.size();
                string right = s.substr(newIdx,  n-newIdx);
                s = left + right;
                i = 0;
                
            } else {
                i++;
            }
        }
        return s;
    }
};