class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    
        sort(nums.begin(), nums.end());
       int i = 0; int n = nums.size();
        int j = n/2;
        
        vector<int> res;
        
        while(i < n/2 || j < n) {
             if(j < n) {
                res.push_back(nums[j++]);
            }
            if(i < n/2) {
                res.push_back(nums[i++]);
            }
           
        }
        return res;
        
        
    }
};