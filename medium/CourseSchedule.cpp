class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& edg) {
        vector<vector<int>> adj(numCourses, vector<int>());
        int pq = edg.size();
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < pq; i++) {
            adj[edg[i][0]].push_back(edg[i][1]);
            inDegree[edg[i][1]]++;
        }
        queue<int> fruits;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i]) continue;
            fruits.push(i);
        }
        vector<int> topSort;

        while (!fruits.empty()) {
            int tp = fruits.front();
            fruits.pop();

            for (int child : adj[tp]) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    fruits.push(child);
                }
            }
            topSort.push_back(tp);
        }
        return topSort.size() == numCourses;
    }
};