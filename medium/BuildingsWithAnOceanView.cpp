class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> res;
        if(n == 0) return res;
        int mx = heights[n-1];
        res.push_back(n-1);
        for(int i = n-1; i>=0; i--) {
            if(heights[i] > mx) {
                res.push_back(i);
                mx = heights[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};