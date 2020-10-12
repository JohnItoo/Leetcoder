class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ct = 1;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pq.push(matrix[i][j]);
            }
        }
        
        while(pq.size() > 0 && ct < k) {
            pq.pop();
            ct++;
        }
        return pq.top();
    }
};