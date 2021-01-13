class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pq) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegrees = buildAdj(pq, adj);
        queue<int> leafs;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) leafs.push(i);
        }
        vector<int> topologicalSort;
        while (!leafs.empty()) {
            int top = leafs.front();
            leafs.pop();
            for (int child : adj[top]) {
                indegrees[child]--;
                if (indegrees[child] == 0) {
                    leafs.push(child);
                }
            }
            topologicalSort.push_back(top);
        }
        if (topologicalSort.size() < numCourses) {
            return vector<int>();
        }
        reverse(topologicalSort.begin(), topologicalSort.end());
        return topologicalSort;
    }

   private:
    vector<int> buildAdj(vector<vector<int>>& pq, vector<vector<int>>& adj) {
        vector<int> degrees(adj.size(), 0);
        for (int i = 0; i < pq.size(); i++) {
            int from = pq[i][0];
            int to = pq[i][1];
            adj[from].push_back(to);
            degrees[to]++;
        }
        return degrees;
    }
};