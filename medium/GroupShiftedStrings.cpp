class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > mp;
        for(string& val : strings) {
            int len = val.length();
            string curr = "";
            
            for(int i = 1; i < len; i++) {
                int diff = 0;
                if(val[i] >= val[i-1]) {
                    diff = val[i] - val[i-1];
                } else {
                    int tillz = 'z' - val[i-1];
                    int froma = val[i] - 'a';
                    diff = tillz + froma + 1;
                }
                string diffstring = to_string(diff);
                curr.append(diffstring);
                curr.push_back('+');
            }
            mp[curr].push_back(val);
        }
        
        vector<vector<string> > result;
        
        for(auto item: mp) {
            result.push_back(item.second);
        }
        return result;
        
    }
};