class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.length();
        int i = 0;
        set<string> st;
        while(i < n) {
            
            if(word[i] >= 'a' && word[i] <= 'z') {
                i++;
                continue;
            }
                int j = i;
                int val = 0;
            string curr = "";
                
                while(j < n && !(word[j] >= 'a' && word[i] <= 'z')) {
                     curr.push_back(word[j]);
                    j++;
                }
                
                int idx = 0;
            while(curr[idx] == '0' && idx < curr.length()) {
                idx++;
            }
            curr = curr.substr(idx, n-idx);
            st.insert(curr);
            i = j;
             
        }
        return st.size();
    }
};