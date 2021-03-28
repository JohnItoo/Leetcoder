class Solution {
   public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            perm[i] = i;
            arr[i] = i;
        }
        vector<int> temp(n);

        bool mv = true;
        int ct = 0;
        int proc = true;

        while (mv) {
            vector<int> temp(n);
            bool cont = true;
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    temp[i] = arr[(n / 2) + (i - 1) / 2];

                } else {
                    temp[i] = arr[i / 2];
                }
            }
            for (int i = 0; i < n; i++) {
                arr[i] = temp[i];
                cont = cont && arr[i] == perm[i];
            }
            if (cont) mv = false;
            ct++;
        }

        return ct;
    }
};