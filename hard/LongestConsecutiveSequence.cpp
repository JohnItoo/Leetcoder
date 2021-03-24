class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        set<int> conc;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            conc.insert(nums[i]);
        }
        int prev = -1e9 - 4;
        auto it = conc.begin();
        int maxct = 0;
        int ct = 0;
        while (it != conc.end()) {
            int curr = *it;
            if (curr != prev + 1) {
                maxct = max(ct, maxct);
                ct = 1;
            } else {
                ct++;
            }
            prev = curr;
            ++it;
        }
        maxct = max(ct, maxct);
        return maxct;
    }
};