class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        bool ans = false;
        set<pair<int,int> > st;
        for(int i = 0; i < n; i++) {
            st.insert(make_pair(nums[i], i));
        }
        auto it = st.begin();
        while(it != st.end()) {
            auto jt = it;
            pair<int,int> jj = *jt;
            pair<int, int> ii = *it;
            
            while(jj.first == ii.first) {
                int diff = abs(jj.second - ii.second);

                if(diff > 0 && diff <= k ) {
                     ans = true;
                    break;
                }
                
                ++jt;
                if(diff != 0) ++it;
                if(it != st.end() && jt != st.end()) {
                    jj = *jt;
                    ii = *it;
                } else {
                    break;
                }
            }
            if(ans) break;
            else it = jt;
        }
        return ans;
    }
};