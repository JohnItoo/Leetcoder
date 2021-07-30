/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int n = dim[0];
        int m = dim[1];
        if(n == 0) return -1;
        
        vector<int> res(m);
        int ct = 0;
        
        int low = 0;
        int high = m-1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/ 2;
            int sm = 0;
            for(int row = 0; row < n; row++) {
                sm += binaryMatrix.get(row, mid);
                if(sm > 0) break;
            }
            if(sm > 0) {
               high = mid-1; 
               ans = mid;
            } else {
                low = mid+1;
            }   
        }
        return ans;
    }
};