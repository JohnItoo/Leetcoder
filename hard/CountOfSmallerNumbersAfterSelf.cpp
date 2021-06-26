class Solution {
public:
    vector<int> segTree;
    void update(int lq, int rq, int lb, int rb, int node) {
       
        if(lq <= lb && rb <= rq) {
            segTree[node] += 1;
            return;
        }
         if(rq < lb || rb < lq) return;
        int mid = (lb + rb)/2;
        update(lq, rq, lb, mid, 2*node);
        update(lq, rq, mid+1, rb, 2*node+1);
    }
    
    int query(int x, int lrange, int rrange, int node) {
        if(lrange == rrange) {
            return segTree[node];
        } 
        int mid = (lrange + rrange) /2;
        int ans = 0;
        if(x <= mid) {
            ans = query(x, lrange, mid, node*2);
        } else {
            ans = query(x, mid+1, rrange, 2*node+1);
        }
        return ans + segTree[node];
    }
    vector<int> countSmaller(vector<int>& nums) {
        int mx = 1e4;
      int add = mx;
      int tot = mx + add;
      while(__builtin_popcount(tot+1) != 1) {
          tot++;
      }
      tot++;
      segTree.resize(2*tot);
      int n = nums.size();
        vector<int> res;
      for(int i = n-1; i >= 0; i--) {
          int val = nums[i];
          int updval = val + add;


          res.push_back(query(updval, 0, tot-1, 1));

          update(updval+1, tot-1, 0, tot-1, 1);
 
      }
      reverse(res.begin(), res.end());
      return res;
    }
};