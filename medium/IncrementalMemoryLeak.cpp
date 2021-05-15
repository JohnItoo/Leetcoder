class Solution {
   public:
    vector<int> memLeak(int ma, int mb) {
        vector<int> res(3);
        int i = 1;
        while (ma >= i || mb >= i) {
            if (mb > ma) {
                mb -= i;
            } else {
                ma -= i;
            }
            i++;
        }
        res[0] = i;
        res[1] = ma;
        res[2] = mb;
        return res;
    }
};