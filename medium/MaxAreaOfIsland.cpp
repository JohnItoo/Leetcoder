class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int arr[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) continue;
                stack<pair<int, int> > st;
                st.push({i, j});
                int visit = 0;
                while(!st.empty()) {
                    pair<int, int> top = st.top(); st.pop();
                    if(grid[top.first][top.second] == 0) continue;
                     grid[top.first][top.second] = 0;
                    visit++;
                    for(int z = 0; z < 4; z++) {
                        int y = top.second + arr[z][1];
                        int x = top.first + arr[z][0];
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0) {
                            st.push({x, y});
                        }
                    }
                }
                ans = max(ans, visit);
            }
        }
        return ans;
    }
};