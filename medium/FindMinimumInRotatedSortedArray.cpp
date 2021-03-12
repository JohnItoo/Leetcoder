class Solution {
 public:
  int findMin(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    int j = len - 1;
    return look(i, j, nums);
  }

 private:
  int look(int i, int j, vector<int>& nums) {
    if (i == j) return nums[i];
    if (i > j) return 1e9 + 8;
    int mid = (j + i) / 2;
    int lef = look(i, mid, nums);
    int rig = look(mid + 1, j, nums);
    return min(lef, rig);
  }
};