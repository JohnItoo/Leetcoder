class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();

        vector<int> res(2);
        int r = n - 1;
        for (int l = 0; l < n; l++) {
            while (r - 1 > l && a[l] + a[r] > target) {
                r--;
            }
            if (a[l] + a[r] == target) {
                res[0]  = l + 1;
                res[1] = r + 1;
                break;
            }
        }

        return res;
    }
};