class Solution {
    
    // isnegative
    //trim function
    //char to int function
    bool isNegative = false;
    int mx = INT_MAX;
    
    
    private: string trim(string s) {
        int len = s.length();
        string res = "";
        int i = 0;
        while(i < len && s[i] == ' ') {
            i++;
        }
        if(s[i] == '-' || s[i] == '+') {
           if(s[i] == '-')
            isNegative = true;
           i++;
        }
        
         while( i < len && s[i] >= '0' && s[i] <= '9')  {
               res.push_back(s[i]);
             i++;
          } 
        return res;
    }
    
    private: int convert(char c) {
        int diff =  c - '0';
        return diff;
    }
   
public:
    int myAtoi(string s) {
        string trimmed = trim(s);
        int len = trimmed.length();
        if(trimmed == "") return 0;
        int curr = 0;
        for(int i = 0; i < len; i++) {
            int x = convert(trimmed[i]);
            if(!isNegative && curr > (mx - x - 1) / 10) {
                return mx;
            } else if(isNegative && curr > (mx - x)/10 ) {
                return -mx-1;
            }
            curr = (curr * 10 ) + x;
        }
        if(isNegative) {
            curr *= -1;
        }
        
        return curr;
    }
};