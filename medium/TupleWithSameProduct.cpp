class Solution {
   public:
    int tupleSameProduct(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> prev;
        int ct = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int pr = a[i] * a[j];
                if (prev.count(pr)) ct += prev[pr];
                prev[pr]++;
            }
        }
        return 8 * ct;
    }
};