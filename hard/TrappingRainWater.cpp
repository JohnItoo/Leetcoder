class Solution {
 
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> res(n, 0);
        vector<int> maxes(n, 0);
        int currMax = -1;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(height[i] >= currMax) {
                currMax = height[i];
                idx = i;
            }
            maxes[i] = idx;
        }
        
        for(int i = 1; i < n; i++) {
            if(height[i] > height[i-1]) {
                int maxTillHereIdx = maxes[i-1];
                int j = i-1;
                int curr = 0;
                while(j > maxTillHereIdx && height[i] >= height[j]) {
                    curr += height[j--];
                }
                int minHeight = min(height[i], height[j]);
                res[i] = res[j] + (minHeight * (i-j-1) ) - curr;
            } else {
                res[i] = res[i-1];
            }
        }
 
        for(int i = n-1; i > -1; i--) {
            if(height[i] >= 0) return res[i];
        }
        return 0;
    }
};