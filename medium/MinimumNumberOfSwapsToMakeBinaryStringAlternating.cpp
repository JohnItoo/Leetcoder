
class Solution {
   public:
    int minSwaps(string s) {
        int ans = 0;
        int n = s.size();
        int len = n;
        int ones = 0, zs = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ones++;
            else
                zs++;
        }
        if ((len & 1) && abs(zs - ones) != 1) {
            return -1;
        }
        if ((len % 2 == 0) && zs != ones) {
            return -1;
        }

        string aux = "";
        string auxtwo = "";
        aux.push_back('1');

        auxtwo.push_back('0');
        int za = zs, zb = zs, onesa = ones, onesb = ones;
        onesa--;
        zb--;
        for (int i = 1; i < n; i++) {
            if (i & 1) {
                aux.push_back('0');

                auxtwo.push_back('1');
                za--;
                onesb--;
            } else {
                aux.push_back('1');
                auxtwo.push_back('0');
                onesa--;
                zb--;
            }
        }
        int diff = 0, diffb = 0;
        for (int i = 0; i < n; i++) {
            if (aux[i] != s[i]) diff++;
            if (auxtwo[i] != s[i]) diffb++;
        }

        ans = -1;
        if (za == 0 && onesa == 0) ans = diff;
        if (zb == 0 && onesb == 0) {
            if (ans == -1)
                ans = diffb;
            else
                ans = min(ans, diffb);
        }
        return ans / 2;
    }
};