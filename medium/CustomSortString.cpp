class Solution {
public:
    string customSortString(string order, string str) {
        map<int, char> mp;
        unordered_set<char> st;
        
        int n = order.size();
        for(int i = 1; i <= n; i++) {
            mp[i] = order[i-1];
            st.insert(order[i-1]);
        }
        n = str.size();
        unordered_set<char> unTagged;
        unordered_map<char, int> strmp;
        
        for(int i = 0; i < n; i++) {
            if(st.find(str[i]) == st.end()) {
                unTagged.insert(str[i]);
            }
            strmp[str[i]]++;
            
        }
        string result;
        for(auto item : mp) {
            char c = item.second;
            if(st.find(c) != st.end()
              && strmp.find(c) != strmp.end()) {
                int times = strmp[c];
                string val = string(times, c);
                result += val;
            } 
        }
        for(auto element : unTagged) {
            int times = strmp[element];
            string val = string(times, element);
             result += val;
        }
        return result;
    }
};