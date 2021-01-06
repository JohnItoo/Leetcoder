class Solution {
   public:
    int getSection(int row, int col) {
        int sectionRow = (row + 2) / 3;
        int sectionCol = 3 - ((col + 2) / 3);
        int section = (3 * sectionRow) - sectionCol;
        return section;
    }
    bool backtrack(vector<vector<char>>& board, int row, int col,
                   vector<map<char, int>>& s, vector<map<char, int>>& r,
                   vector<map<char, int>>& c) {
        if (row == 10) return true;
        if (col == 10) return backtrack(board, row + 1, 1, s, r, c);
        if (board[row - 1][col - 1] != '.')
            return backtrack(board, row, col + 1, s, r, c);
        for (char i = '1'; i <= '9'; i++) {
            int currsection = getSection(row, col);
            if (s[currsection].find(i) != s[currsection].end() ||
                r[row].find(i) != r[row].end() ||
                c[col].find(i) != c[col].end())
                continue;

            r[row][i] = 1;
            s[currsection][i] = 1;
            c[col][i] = 1;
            board[row - 1][col - 1] = i;
            if (backtrack(board, row, col + 1, s, r, c)) return true;
            board[row - 1][col - 1] = '.';
            c[col].erase(i);
            s[currsection].erase(i);
            r[row].erase(i);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<map<char, int>> sections(10);
        vector<map<char, int>> rows(10);
        vector<map<char, int>> cols(10);

        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                int r = i - 1;
                int c = j - 1;
                if (board[r][c] == '.') continue;
                char ch = board[r][c];
                rows[i][ch] = 1;
                cols[j][ch] = 1;
                sections[getSection(i, j)][ch] = 1;
            }
        }
        backtrack(board, 1, 1, sections, rows, cols);
    }
};