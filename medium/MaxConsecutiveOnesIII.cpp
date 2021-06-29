class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int tots = 0, convs = 0, i = 0, j = 0, ans = 0;
        
        while(j < n) {
            while(j < n && convs <= k) {
                if(!nums[j] && convs ==k) break;
                if(nums[j] == 0 ) {
                    convs++;
                }
                tots++;
                ans = max(ans, tots);

                j++;
            }
            while(convs == k) {
                if(convs == 0) {
                   j++;
                    tots =0;
                    break;
                }
                if(nums[i] == 0) {
                    convs--;
                }
                tots--;
                ans = max(ans, tots);
                i++;
            }
        }
        ans = max(ans, tots);
        return ans;
    }
};