class Solution {
    using ll = long long;
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
   
        ll prev = 0;
        int i = 0;
        ll ans = 0;
        int n = nums.size();
        while(i < n && k > 0) {
            int next = prev + 1;
            if(nums[i] >  next) {
            int diff = (nums[i] - 1) - prev;
            int take = min(k, diff);
            k -= take;
           
            int start = 2*(next);
            ll loc = take * 1LL * ((start + (take-1)))/2;
          ans += loc;

                   
         }
            prev = nums[i];
            i++;
            
            
        }
        if(k > 0) {
            int next = prev + 1;
            int take = k;
             int start = 2*next;
            ll loc = take * 1LL * ((start + (take-1)))/2;
            ans += loc;
        }
        return ans;
    }
};