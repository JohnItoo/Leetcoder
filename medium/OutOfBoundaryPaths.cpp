class Solution {
public:
    int dir[4][2] = { {1, 0}, {0, 1} , {-1, 0}, {0, -1}};
    int mod = 1e9 + 7;
     int backtrack(int m, int n, int maxMove, int r, int c,  map<pair<int, int>, int >& cache) {
 
        if(!(r >= 0 && r < m && c >= 0 && c < n)) {
                 return 1;
        }
    
         if(!(maxMove)) {
             return 0;
         }
         
        
         int ans = 0;
         pair<int, int> pairhere = {r*n + (c+1), maxMove};
         if(cache.find(pairhere) != cache.end()) {
             return cache[pairhere];
         }
         
         for(int i = 0; i < 4; i++) {
             int nr = dir[i][0] + r;
             int nc = dir[i][1] + c;
               ans +=  backtrack(m, n, maxMove-1, nr, nc, cache);
               ans %= mod;
             
         }
         cache[pairhere] = ans;
         return ans;
        
     }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        map<pair<int, int>, int> mp;
        return backtrack(m, n, maxMove, startRow, startColumn, mp);
    }
};