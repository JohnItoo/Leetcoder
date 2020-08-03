#include <bits/stdc++.h>
using namespace std;

public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {

	int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
	int m = matrix.size();
	vector<int> solution;
	if (m == 0) return solution;

	int n = matrix[0].size();
	int cells = m * n;
	int start = 0;
	vector<vector<bool> > picked(m, vector<bool>(n, false));
	int i = 0;
	int j = 0;
	long long move = 0;
	while (start < cells) {
		picked[i][j] = true;
		start++;
		solution.push_back(matrix[i][j]);
		int mr = dir[move % 4][0];
		int mc = dir[move % 4][1];
		int nr = i + mr;
		int nc = j + mc;
		if (nr < 0 || nr >= m || nc < 0 || nc >= n || picked[nr][nc]) {
			move++;
			mr = dir[move % 4][0];
			mc = dir[move % 4][1];
			nr = i + mr;
			nc = j + mc;
		}
		i = nr;
		j = nc;
	}
	return solution;
}