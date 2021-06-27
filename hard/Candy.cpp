class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int, int> , vector<pair<int, int> > , greater<>> pq;
        int n = ratings.size();
        for(int i = 0; i < n; i++) {
            pq.push({ratings[i], i});
        }
        vector<int> ans(n,0);
        while(!pq.empty()) {
            pair<int, int>  node = pq.top();
            pq.pop();
            int rating = node.first;
            int idx = node.second;
            if(idx > 0 && ratings[idx-1] < ratings[idx]) ans[idx] = ans[idx-1] + 1;
            if(idx + 1< n && ratings[idx+1] < ratings[idx]) ans[idx] = max(ans[idx], ans[idx+1] +1);
            if(ans[idx] == 0) ans[idx] = 1;
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};