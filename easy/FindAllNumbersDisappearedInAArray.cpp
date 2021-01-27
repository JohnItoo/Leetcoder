class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == i + 1) continue;
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};