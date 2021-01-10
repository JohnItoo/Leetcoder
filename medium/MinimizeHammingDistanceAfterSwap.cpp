class Solution {
   public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& as) {
        int mx = 1e5 + 8;
        vector<vector<int>> adj(mx, vector<int>());
        int n = as.size();
        for (int i = 0; i < n; i++) {
            adj[as[i][0]].push_back(as[i][1]);
            adj[as[i][1]].push_back(as[i][0]);
        }
        map<int, int> visited;
        int m = source.size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            if (visited.count(i)) continue;
            queue<int> q;
            q.push(i);
            map<int, int> tg;
            map<int, int> sc;
            int comp = 0;
            while (!q.empty()) {
                int tp = q.front();
                q.pop();
                if (visited.count(tp)) continue;
                visited[tp] = 1;
                comp++;
                tg[target[tp]]++;
                sc[source[tp]]++;
                for (int child : adj[tp]) {
                    q.push(child);
                }
            }
            int val = 0;
            for (auto xx : tg) {
                if (sc.count(xx.first)) {
                    val += min(xx.second, sc[xx.first]);
                }
            }
            ans += comp - val;
        }
        return ans;
    }
};