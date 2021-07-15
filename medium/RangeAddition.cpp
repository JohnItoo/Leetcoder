class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = updates.size();
        vector<int> pref(length, 0);
        for(int i = 0; i < n; i++) {
            int startIdx = updates[i][0];
            int endIdx = updates[i][1];
            int val = updates[i][2];
            pref[startIdx] += val;
            if(endIdx+1 <= length-1) {
                pref[endIdx+1] -= val;
            }    
        }
        
        vector<int> res(length);
        res[0] = pref[0];
        
        
        for(int i = 1; i < length; i++) {
            res[i] = res[i-1] + pref[i];
        }
        return res;
    }
};