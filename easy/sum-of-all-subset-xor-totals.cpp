// O(2^N) solution recursive backtracking
class Solution {
   public:
    int ans, len;
    vector<int> ext;
    void bt(vector<int>& subs, int n) {
        if (n == len) {
            int v = subs.size();
            if (v != 0) {
                int prev = subs[0];
                for (int i = 1; i < v; i++) {
                    prev = prev ^ subs[i];
                }
                ans += prev;
            }
            return;
        }
        bt(subs, n + 1);
        subs.push_back(ext[n]);
        bt(subs, n + 1);
        subs.pop_back();
    }
    int subsetXORSum(vector<int>& nums) {
        ans = 0;
        len = nums.size();
        ext = nums;
        vector<int> subs;
        bt(subs, 0);
        return ans;
    }
};

//
class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 1; i < (1 << n); i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curr ^= nums[j];
                }
            }
            total += curr;
        }
        return total;
    }
};