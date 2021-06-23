class NumArray {
public:
    vector<long long> tree;
    int ct = 0;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        while(__builtin_popcount(n) != 1) {
            n++;
            nums.push_back(0);
        }
        ct = n;
        tree.resize(2*n);
        
        for(int i = 2*n-1, j = n-1; j >=0;  i--, j--) {
            tree[i] = nums[j] * 1LL;
        }
        
        for(int i = n-1; i > 0 ;  i--) {
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    
    void update(int index, int val) {
       int segIdx = index + ct;
        int diff =  val - tree[segIdx];
        while(segIdx) {
            tree[segIdx] += diff;
            segIdx /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        return getSumRange(left, right, 0, ct-1,1);
    }
    private: 
    long long getSumRange(int lq, int rq, int left, int right, int node) {
        if(lq <= left && right <= rq) return tree[node];
        if(right < lq || rq < left) return 0;
        int rightOfLeftMostChild = (left + right )/ 2;
        return getSumRange(lq, rq, left, rightOfLeftMostChild, 2*node) + 
              getSumRange(lq, rq, rightOfLeftMostChild + 1,right, 2*node+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */