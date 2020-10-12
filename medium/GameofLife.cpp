class Solution {
    int N, M;

    bool vld(int i , int j) {
        return (i >= 0 && i < N && j >= 0 && j < M);
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) return;
        N = board.size();
        M = board[0].size();

        vector<vector<int>> copy(N, vector<int>(M, 0));

        int moves[8][2] = {{ -1, -1}, { -1, 0} , { -1, 1} , {0, 1}, {1, 1}, {1, 0}, {1, -1} , {0, -1}};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int liveng = 0;
                for (int k = 0; k < 8; k++) {
                    int r = i + moves[k][0];
                    int c = j + moves[k][1];
                    if (vld(r, c)) liveng += board[r][c];
                }

                if (board[i][j]) {
                    if (liveng < 2 || liveng > 3) copy[i][j] = 0;
                    else copy[i][j] = 1;

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