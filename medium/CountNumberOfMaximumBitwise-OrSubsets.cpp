class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    map<int, int> vals;
    int n = nums.size();
    int mx = INT_MIN;
    for (int b = 0; b < (1 << n); b++) {
      int val = 0;
      for (int i = 0; i < n; i++) {
        if (b & (1 << i)) {
          if (i == 0) {
            val = nums[i];
          } else {
            val |= nums[i];
          }
        }
      }
      vals[val]++;
      mx = max(mx, val);
    }
    return vals[mx];
  }
};