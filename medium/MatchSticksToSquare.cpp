class Solution {
   public:
    bool recurse(int target, int sum, int idx, int remSubsets, vector<int>& ms,
                 vector<bool>& vs) {
        if (remSubsets == 1) return true;
        if (target == sum) {
            return recurse(target, 0, 0, remSubsets - 1, ms, vs);
        }
        for (int i = idx; i < ms.size(); i++) {
            if (vs[i]) continue;
            vs[i] = true;
            if (recurse(target, sum + ms[i], i, remSubsets, ms, vs))
                return true;
            vs[i] = false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        if (sum % 4) {
            return false;
        }
        int target = sum / 4;
        vector<bool> visited(matchsticks.size(), false);
        return recurse(target, 0, 0, 4, matchsticks, visited);
    }
};