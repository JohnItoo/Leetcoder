class Solution {
public:
    string removeConsecutive(string& p) {
      string res;
        
        int n = p.size();
        for(int i = 0; i < n; i++) {
            if(p[i] == '*' && i+1 < n && p[i+1] == '*') continue;
            res.push_back(p[i]);
        }
        return res;
    }
    bool match(string& s, string& p, int i , int j, vector<vector<int> >& mem) {
        if(mem[i][j] != 0) {
            return mem[i][j] > 0;
        }
        /**
        s and p are both empty - true;
        s is empty and p is just "*"- true;
        s and p are non empty and 
           they match  return true;
           p[j] == '?' return match(i+1, j+1);
           p[j] == '*' return match(i+1, j) || match(i, j+1);
        
        
        **/
        int n = s.size();
        int m = p.size();
        bool valid = false;
        if(i < n && j < m) {
           string ssub = s.substr(i);
            string psub = p.substr(j);
            if(ssub == psub || (j == m-1 && p[j] == '*') ) {
                valid = true;
            }
            else if(s[i] == p[j] || p[j] == '?') {
                valid = match(s, p, i+1, j+1, mem);
            } else if(p[j] == '*') {
                valid = match(s, p, i, j+1, mem) || match(s, p, i+1, j, mem);
            }
        } else if((i == n && j == m) || j + 1 == m && p[j] == '*') {
            valid = true;
        } 
        if(valid) {
            mem[i][j] = 1;
        } else {
            mem[i][j] = -1;
        }
        return valid;
    }
    bool isMatch(string s, string p) {
       string valp = removeConsecutive(p);
       int n = s.size();
       int m = valp.size();
        vector<vector<int> > mem(n+1, vector<int>(m+1, 0)); 
        
       return match(s, valp, 0 , 0, mem);
    }
};