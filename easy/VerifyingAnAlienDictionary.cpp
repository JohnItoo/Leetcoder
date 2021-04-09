class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        unordered_map<char, int> dict;
        int len = order.length();
        for(int i = 0; i < len; i++) {
            dict[order[i]] = i+1;
        }
       int i = 0; bool valid = true;
        while(i < n && valid) {
            int j = i+1;
            string here = words[i];
            while(j < n) {
                string curr = words[j];
                bool isGreater = true;
                int hl = here.length();
                int cl = curr.length();
                int p = 0, q = 0;
                while(p < hl && q < cl && dict[here[p]] == dict[curr[q]]) {
                    p++; q++;
                }
                
                if(p < hl && q < cl && dict[here[p]] > dict[curr[q]]) {
                    valid = false;
                } else if(q == cl && p < hl) {
                    valid = false;
                }
                if(!valid) break;
                j++;
            }
            i++;
        }
        return valid;
    }
};