class Solution {
    vector<vector<string>> result;

public: bool cantPlace( map<int, int> left, map<int, int> right, map<int, int> column, int i, int j, int n) {
        return (column.find(j) != column.end()) || right.find((n + i - j)) != right.end() || left.find((n - i - j)) != left.end();
    }

public: void backtrack(int row, int n, map<int, int> left, map<int, int> right, map<int, int> column, vector<string> board) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cantPlace(left, right, column, row, j, n)) continue;
            board[row][j] = 'Q';
            left[n - row - j] = 1;
            right[n + row - j] = 1;
            column[j] = 1;
            backtrack(row + 1, n, left, right, column, board);
            board[row][j] = '.';
            left.erase(n - row - j);
            right.erase(n + row - j);
            column.erase(j);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        for (int col = 0; col < n; col++) {
            map<int, int> leftDiagonal;
            map<int, int> rightDiagonal;
            map<int, int> column;
            column[col] = rightDiagonal[n + 0 - col] = leftDiagonal[n - 0 - col] = 1;
            string rowString = string(n, '.');
            vector<string> board(n, rowString);
            board[0][col] = 'Q';
            backtrack(1, n, leftDiagonal, rightDiagonal, column, board); // place a queen on the zeroth row and the colth column; then backtrack.
        }
        return result;
    }
};