class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> res(nums.size() + 1, 0);
       
        
        for(int i = 1; i <= nums.size(); i++) {
            res[i] = (nums[i-1] + res[i-1]);
        }
        
        map<int, vector<int>> mp;
        int mx = -1;
        
        for(int i = 0; i <= nums.size(); i++) {
             int lef = i - res[i] + res[0];
            int right = res[nums.size()] - res[i];
            mx = max(mx, lef + right);
            mp[lef+ right].push_back(i);
        }
        return mp[mx];
    }
};