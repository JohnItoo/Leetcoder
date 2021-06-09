class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        priority_queue<pair<int, int> > pq;
        pq.push({nums[0], 0});
        for(int i = 1; i < n; i++) {
            while(!pq.empty() && pq.top().second < i-k) pq.pop();
            dp[i] = pq.top().first + nums[i];
            cout << dp[i] << " ";
            pq.push({dp[i], i});
        }
        return dp[n-1];
    }
};


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < n; i++) {
          int toadd = dp[dq.front()] + nums[i];
          if(dq.front() == i-k) dq.pop_front();
          while(!dq.empty() && dp[dq.back()] < toadd) dq.pop_back();
          
          dp[i] = toadd;
          dq.push_back(i);
        }
        return dp[n-1];
    }
};