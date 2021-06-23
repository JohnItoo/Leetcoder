class Solution {
public:
    bool dfs(vector<bool>& visited, int source, int dest, vector<vector<int> >& adj) {
        if(visited[source]) return false;
        if(adj[source].size() == 0)return source == dest;
        if(source == dest) return false;
        visited[source] = true;
        bool ans = true;
        for(auto edge : adj[source]) {
          ans &= dfs(visited, edge, dest, adj);
          if(!ans) return false;
        }
      visited[source] = false;
        return ans;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int> > adj(n+3, vector<int>());
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> visited(n+3, false);
       return dfs(visited, source, destination, adj);
    }
};