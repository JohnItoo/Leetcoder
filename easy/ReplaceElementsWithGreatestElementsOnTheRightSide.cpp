class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        result[n - 1] = -1;
        if (n >= 2) result[n - 2] = arr[n - 1];
        int mx = -1;
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, arr[i + 1]);
            result[i] = mx;
        }
        return result;
    }
};