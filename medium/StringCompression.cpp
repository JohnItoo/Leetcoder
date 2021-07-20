class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j = 0, ans = 0;
        int curr = 0;
        
        while(i < n) {
           if(i + 1 == n || chars[i] != chars[i+1]) {
               int val = i - curr + 1;
               chars[j++] = chars[i++];
               if(val > 1) {
                   string valst = to_string(val);
                   for(int x = 0; x < valst.size(); x++) {
                       chars[j++] = valst[x];
                   }
               }
               curr = i;
           } else {
               i++;
           }
        } 
        return j;
         
    }
};