class SparseVector {
public:
    map<int, int> sparsemap;
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for(int i = 1; i <=n; i++) {
            if(nums[i-1]) {
                 sparsemap[i] = nums[i-1];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        map<int, int> vecsparsemap = vec.sparsemap;
        int ans = 0;
        for(auto ii : sparsemap) {
            int idx = ii.first;
            int val = ii.second;
            if(vecsparsemap.find(idx) != vecsparsemap.end()) {
                ans += (val * vecsparsemap[idx]);
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);