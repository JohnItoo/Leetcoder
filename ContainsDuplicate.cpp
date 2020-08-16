class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        bool does = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                does = true;
                break;
            }
        }
        return does;
    }
};