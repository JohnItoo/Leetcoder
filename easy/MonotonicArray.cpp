class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i + 1 < n && nums[i] == nums[i+1]) {
            i++;   
        }
        if(i + 1 >= n) return true;
        bool dec = nums[i] > nums[i+1];
        int val = nums[i++];
        while(i < n) {
            if(dec &&  nums[i] > val) return false;
            if(!dec && nums[i] < val) return false;
            val = nums[i++];
        }
        return true;
    }
};