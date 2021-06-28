class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int last = 0;
            bool fd = true;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(last >= nums[j]){ fd = false; break;}
                last = nums[j];
            }
            if(fd) return true;
        }
        return false;
    }
};