class Solution {
public:
    bool isWithin(int r, int c, int n, int m) {
        return (r  >= 0 && r < n && c < m && c>=0);
    }
    bool isBorder(int r, int c, int n, int m) {
        return (r == 0 || r == n-1 || c == 0 || c == m-1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        map<pair<int, int> , int> done;
      
        for(int k = 0; k < n; k++) {
             for(int i = 0; i <m; i++) {
           if(!isBorder(k, i, n, m) ||  board[k][i] == 'X' || done.count(make_pair(k, i))) continue;
            stack<pair<int, int> > st;
            st.push(make_pair(k, i));
            while(!st.empty()) {
                pair<int, int> top = st.top(); st.pop();
                if(done.count(top)) continue;
                done[top] = 1;
                for(int j = 0; j  < 4; j++) {
                    int nr = top.first + dir[j][0];
                    int nc = top.second + dir[j][1];
                    if(isWithin(nr, nc, n, m) && board[nr][nc] == 'O') {
                        st.push(make_pair(nr, nc));
                    }
                }
            }  
        }
        }

   
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++ ) {
                pair<int, int> curr = make_pair(i, j);
                if(board[i][j] == 'O' && !isBorder(i, j, n,m) && done.count(curr) == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};