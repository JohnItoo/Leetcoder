class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int len = n;

        for (int i = 0; i < n / 2; i++) {
            pair<int, int> p = make_pair(i, i);
            pair<int, int> q = make_pair(i, len - 1);
            pair<int, int> r = make_pair(len - 1, len - 1);
            pair<int, int> s = make_pair(len - 1, i);

            for (int j = i; j < len - 1; j++) {
                int oldp = matrix[p.first][p.second];
                int oldq = matrix[q.first][q.second];
                int oldr = matrix[r.first][r.second];
                int olds = matrix[s.first][s.second];

                matrix[p.first][p.second] = olds;
                matrix[q.first][q.second] = oldp;
                matrix[r.first][r.second] = oldq;
                matrix[s.first][s.second] = oldr;

                p.second = p.second + 1;
                q.first = q.first + 1;
                r.second -= 1;
                s.first -= 1;

            }

            len -= 1;
        }

    }
};