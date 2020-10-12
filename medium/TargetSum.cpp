class Solution {
    int numWays = 0;
    int target = 0;
    void backtrack(int curr, vector<int> &nums, int total) {
        if (curr == nums.size()) {
            if (total == target) {
                numWays += 1;
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                backtrack(curr + 1, nums, total - nums[curr]);
            } else {
                backtrack(curr + 1, nums, total + nums[curr]);
            }
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        target = S;

        backtrack(0, nums, 0);
        return numWays;

    }
};