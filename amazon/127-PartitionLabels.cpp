class Solution {
public:
    int partitionSize(int start, string s) {
        int i = start; 
        int lim = start;
        map<char, int> mp;
        while(i <= lim) {
            if(mp.find(s[i]) != mp.end()) {
                i++;
                continue;
            }
            mp[s[i]] = 1;
            int j = s.length()-1;
            while(j > lim && s[i] != s[j]) j--;
            lim = j;
            i++;
        }
        return (lim - start) + 1;
    }
    vector<int> partitionLabels(string s) {
        int n = s.length();
        
       int start = 0;
       vector<int> result;
       while(start < n) {
           int size = partitionSize(start, s);
           result.push_back(size);
           start += size;
       }
        return result;
        
    }
};