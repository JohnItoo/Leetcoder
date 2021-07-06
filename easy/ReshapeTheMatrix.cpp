class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int> > res(r, vector<int>(c));
        int n = mat.size();
        if(n == 0) {
          vector<vector<int> > curr;
            return curr;
        }
        
        
        int m = mat[0].size();
        if(m*n != r*c) {
            return mat;
        }
        
        int lefi = 0;
        int rigi = 0;
        int lefj = 0;
        int rigj = 0;
        while(lefi < n) {
            if(lefj >= m) {
                lefi++;
                lefj = 0;
            } else if(rigj >= c) {
                rigi++;
                rigj = 0;
            } else {
                res[rigi][rigj++] = mat[lefi][lefj++];
            }
        }
        return res;
    }
};