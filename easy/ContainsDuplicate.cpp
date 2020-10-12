class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        bool does = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                does = true;
                break;
            }
        }
        return does;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        bool ans = false;
        for(int i = 0; i < n; i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
            } else {
                ans = true;
                break;
            }
        }
        return ans;
    }
};