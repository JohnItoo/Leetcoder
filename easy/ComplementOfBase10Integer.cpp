class Solution {
public:
    int bitwiseComplement(int n) {
       vector<int> bits(32);
        if(n == 0) return 1;
       
        for(int i = 0; 1 << i <= n; i++) {
            if(n & (1 << i)) {
                bits[i] = 0;
            } else {
                bits[i] = 1;
            }
        }
        int res = 0;
        
        for(int i = 0; 1 << i <= n; i++) {
            if(bits[i]) {
                res += (1 << i);
            }
        }
        return res;
    }
};