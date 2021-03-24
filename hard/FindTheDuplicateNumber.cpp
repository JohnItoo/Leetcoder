class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (i + 1 != nums[i] && nums[nums[i] - 1] != nums[i]) {
                int x = nums[i] - 1;
                int y = nums[x];
                nums[i] = y;
                nums[x] = x + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return nums[i];
            }
        }
        return 0;
    }
};