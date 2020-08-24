class Solution {
    private: 
     set<pair<int,int> > st;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            st.insert(make_pair(nums[i], i));
        }
    }
    
    int pick(int target) {
        pair<int,int> ii = make_pair(target, -1);
        auto it = st.upper_bound(ii);
        vector<int> res;
        while(it != st.end()) {
          pair<int,int> curr = *it;
            if(curr.first != target) break;
            res.push_back(curr.second);
            ++it;
        }
        int x = rand() % res.size();
        
        
        return res[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */