class Solution {
    int N, M;

    bool vld(int i, int j) { return (i >= 0 && i < N && j >= 0 && j < M); }

   public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) return;
        N = board.size();
        M = board[0].size();

        vector<vector<int>> copy(N, vector<int>(M, 0));

        int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                           {1, 1},   {1, 0},  {1, -1}, {0, -1}};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int liveng = 0;
                for (int k = 0; k < 8; k++) {
                    int r = i + moves[k][0];
                    int c = j + moves[k][1];
                    if (vld(r, c)) liveng += board[r][c];
                }

                if (board[i][j]) {
                    if (liveng < 2 || liveng > 3)
                        copy[i][j] = 0;
                    else
                        copy[i][j] = 1;

                } else {
                    if (liveng == 3) copy[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = copy[i][j];
            }
        }
    }
};

// USING MAP WITHOUT ALLOCATING COPY

class Solution {
   public:
    bool isValid(int n, int m, int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    int getIdx(int r, int c, int m) { return (r * m) + (c + 1); }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        map<int, int> liveCells;
        int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                         {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbours = 0;
                for (int k = 0; k < 8; k++) {
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if (!isValid(n, m, r, c) || board[r][c] == 0) continue;
                    neighbours++;
                }

                int val = getIdx(i, j, m);

                if (neighbours == 3) {
                    liveCells[val] = 1;
                } else if (neighbours == 2 && board[i][j] == 1) {
                    liveCells[val] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = getIdx(i, j, m);
                if (liveCells.count(val)) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};

//IN PLACE

class Solution {
public:
    bool isValid(int n, int m, int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
 
        int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1} , {1, 1}, {1, 0}, 
                         {1, -1}, {0, -1}, {-1, -1} };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int neighbours = 0;
                for(int k = 0; k < 8; k++) {
                    int r = i+ dir[k][0];
                    int c = j + dir[k][1];
                    if(!isValid(n, m, r, c) || board[r][c] == 0 || board[r][c] == 4) continue;
                    neighbours++;
                }
                
            
                if(neighbours == 3) {
                    board[i][j] = (board[i][j] == 0) ? 4 : 2;
                } else if(neighbours == 2 && board[i][j] == 1) {
                    board[i][j] = 2;
                } else if(board[i][j] == 1) {
                    board[i][j] = 3;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 0 || board[i][j] == 3) {
                    board[i][j] = 0;
                } else {
                    board[i][j] = 1;
                }
            }
        }
    }
};