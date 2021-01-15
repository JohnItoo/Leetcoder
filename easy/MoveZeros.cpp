class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        int pointer = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[pointer] = nums[i];
                pointer++;
            }
        }

        while (pointer < n) {
            nums[pointer++] = 0;
        }
    }
};