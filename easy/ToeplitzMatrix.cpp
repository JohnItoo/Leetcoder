// Toeplitz Matrix
// https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>
using namespace std;

public:
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    bool found = true;

    int r = matrix.size();
    int c = matrix[0].size();

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (i - 1 < 0 || j - 1 < 0) continue;
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                found = false;
                break;
            }
        }
        if (!found) break;
    }

    return found;
}