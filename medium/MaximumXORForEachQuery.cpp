class Solution {
   public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
        vector<int> res;
        int n = nums.size();
        vector<int> ors;
        ors.push_back(nums[0]);
        int mx = -1, val = -1;
        int lim = 1 << bit;
        for (int j = 0; j < lim; j++) {
            int dx = nums[0] ^ j;
            if (dx > val) {
                val = dx;
                mx = j;
            }
        }

        res.push_back(mx);

        for (int i = 1; i < n; i++) {
            int curr = ors[ors.size() - 1];
            curr = curr ^ nums[i];
            mx = -1, val = -1;
            mx = curr ^ (lim - 1);
            res.push_back(mx);

            ors.push_back(curr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};