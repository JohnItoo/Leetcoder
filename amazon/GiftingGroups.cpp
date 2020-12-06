class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    vector<vector<int> > graph(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (M[i][j]) {
          graph[i + 1].push_back(j + 1);
        }
      }
    }
    map<int, int> visited;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (visited.find(i) != visited.end()) continue;
      stack<int> dfs;
      dfs.push(i);
      ans += 1;
      while (!dfs.empty()) {
        int tp = dfs.top(); dfs.pop();
        if (visited.find(tp) != visited.end()) continue;
        visited[tp] = 1;
        for (int edge : graph[tp]) {
          dfs.push(edge);
        }
      }
    }

    return ans;


  }
};