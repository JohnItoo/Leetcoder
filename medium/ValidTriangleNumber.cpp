class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> starts(10005); // the last time something was less than i
        int i = 0;
        int j = 0;
        int idx = -1;
        while(j < n) {
            while(i <= nums[j]) {
                starts[i] = idx;
                i++;
            }
            while(j+1 < n && nums[j] == nums[j+1]) {
                j++;
                idx++;
            }
            idx = j;
            j++;
        }
        for(int i = nums[n-1] + 1; i <= 1000; i++) {
            starts[i] = n-1;
        }
         int max_el = *max_element(nums.begin(), nums.end());
    
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int mx = nums[i] + nums[j];
                int res = 0;
                if(mx > max_el) {
                    res = n-1 - j;
                } else {
                    res = starts[mx] - j;
                }
                if(res < 0) continue;
                ans += (res * 1LL);
            }
        }
        
        return ans;
    }
};