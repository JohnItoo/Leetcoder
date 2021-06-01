class Solution {
    //RECURSION AND MEMOIZATION
   public:
    int recur(int idx, int prevColor, vector<vector<int>>& costs,
              map<pair<int, int>, int>& mem) {
        int n = costs.size();
        if (idx == n) {
            return 0;
        }
        if (mem.count({idx, prevColor})) {
            return mem[{idx, prevColor}];
        }

        int ans = INT_MAX;
        for (int i = 0; i < 3; i++) {
            if (i == prevColor) continue;
            ans = min(ans, costs[idx][i] + recur(idx + 1, i, costs, mem));
        }
        mem[{idx, prevColor}] = ans;
        return ans;
    }
    int costPaint(vector<vector<int>>& costs, map<pair<int, int>, int>& mem) {
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++) {
            ans = min(ans, costs[0][i] + recur(1, i, costs, mem));
        }

        return ans;
    }
    int minCost(vector<vector<int>>& costs) {
        map<pair<int, int>, int> mem;
        return costPaint(costs, mem);
    }
};


class Solution {
    //DP
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int> > dp(n, vector<int>(3, INT_MAX));
        for(int i = 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) { // we are going to paint i j
                for(int k = 0; k < 3; k++) {
                    if(j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i][j]);
                }
            }
        }
        
        return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    }
};