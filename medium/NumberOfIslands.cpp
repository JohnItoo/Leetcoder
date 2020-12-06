class Solution {
    int dir[4][2] = { {0, -1}, {0, 1}, { -1, 0}, {1, 0} };
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =  grid[0].size();
        int ans = 0;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                queue<pair<int, int>> bfs;
                bfs.push(make_pair(i, j));
                ans++;

                while (!bfs.empty()) {
                    pair<int, int> front = bfs.front(); bfs.pop();
                    if (grid[front.first][front.second] == '0') continue;
                    int r = front.first;
                    int c = front.second;
                    grid[r][c] = '0';
                    for (int mv = 0; mv < 4; mv++) {
                        int nr = r + dir[mv][0];
                        int nc = c + dir[mv][1];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '0') continue;
                        bfs.push(make_pair(nr, nc));
                    }
                }
            }
        }
        return ans;

    }
};