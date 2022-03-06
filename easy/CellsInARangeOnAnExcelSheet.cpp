class Solution {
public:
    vector<string> cellsInRange(string s) {
        int i = 1;
        while(s[i] != ':') {
            i++;
        }
        string begstr = s.substr(1, i-1);
        int beg = stoi(begstr);
        
        int mark = i+1;
        i += 2;
        
        string endstr = s.substr(i , s.size() - i);
        int end = stoi(endstr);
        vector<string> res;
        
        for(char c = s[0]; c <= s[mark]; c++) {
            for(int x = beg; x <= end;  x++ ) {
                string left = string(1, c);
                string right = to_string(x);
                res.push_back(left + right);
            }
        }
        return res;
        
    }
};