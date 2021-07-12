class Solution {
public:
    int getId(int r, int c, int cols) {
        return r * cols + c+1;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        map<int, pair<int, int> > mapping;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mapping[getId(i, j, m)] = {i, j};
            }
        }
        
        //You can only swim to a neighbour at time t if height of current cell and dest are  not greater than t
        //The min time you can swim to a neighbour is the greater between least time to get to this cell and height of that neighbour
        vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0]; // dist is current height  at time you got to position i, j. height and time are similar heregrid[0][0]
        priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
        pq.push({grid[0][0], 1});
        unordered_map<int, int> done;
        int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!pq.empty()) {
            pair<int, int> tp = pq.top(); pq.pop();
            if(done.find(tp.second) != done.end()) continue;
            done[tp.second] = 1;
            pair<int, int> rc = mapping[tp.second];
            for(int i = 0; i < 4; i++) {
                int nr = rc.first + dir[i][0];
                int nc = rc.second + dir[i][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int currentTime = dist[rc.first][rc.second];
                int mx = max(currentTime, grid[nr][nc]);
                if(mx < dist[nr][nc]) {
                    dist[nr][nc] = mx; //
                    pq.push({mx, getId(nr, nc, m)});
                }
            }

        }
        return dist[n-1][m-1];
    }
};