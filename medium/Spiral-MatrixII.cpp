class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        vector<vector<int> > matrix(n, vector<int>(n, 0));


        int done = 1;
        int idx = 0;
        int row = 0;
        int col = 0;
        matrix[row][col] = 1;

        while (done <  n * n) {
            int curr = idx % 4;
            while (row + directions[curr][0] >= 0 &&
                    row + directions[curr][0] < n &&
                    col + directions[curr][1] >= 0 &&
                    col + directions[curr][1] < n &&
                    matrix[row + directions[curr][0]][col + directions[curr][1]] == 0
                  ) {
                done++;
                row += directions[curr][0];
                col += directions[curr][1];
                matrix[row][col] = done;
            }
            idx++;
        }
        return matrix;
    }
};