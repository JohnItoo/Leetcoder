class Solution {
    typedef long long ll;
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 7) return false;
        vector<ll> prefSum(n+1, 0LL);
        for(int i = 1; i <= n; i++) {
            prefSum[i] = nums[i-1] + prefSum[i-1];
        }
        
        int i = 2; // index 1
        int k = n-1; // index n-2
        bool fd = false;
        vector<pair<int, int> > equalBorders;
        
        for(int i = 2; i + 4 <= n-1; i++) {
            for(int k = i+4; k <= n-1; k++)  {
                ll rightBorder = prefSum[n] - prefSum[k];
                if(prefSum[i-1] == rightBorder) {
                    equalBorders.push_back({i, k});
                }
            }
        }
        
        for(pair<int, int> border : equalBorders) {
            int i = border.first;
            int k = border.second;
            
            for(int j = i+2; j <= k -2; j++) {
                    int left = prefSum[j-1] - prefSum[i];
                    int right = prefSum[k-1] - prefSum[j];
                    if( left == right  && left == prefSum[i-1]) return true;
             }
        }
        return false;
        
        
    }
};