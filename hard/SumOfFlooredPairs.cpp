class Solution {
   public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;
        long mod = 1e9 + 7;
        int bg = 1e5 + 1;
        long mx = *max_element(nums.begin(), nums.end());
        vector<long> freq(2 * bg + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        for (int i = 1; i <= 2 * bg; i++) {
            freq[i] += freq[i - 1];
        }

        for (int i = 0; i < n; i++) {
            long mult = 1;
            long left = nums[i];
            long right = 2 * nums[i] - 1;
            while (left <= mx) {
                ans = (ans + mult * (freq[right] - freq[left - 1])) % mod;
                left += nums[i];
                right += nums[i];
                mult++;
            }
        }
        return ans;
    }
};