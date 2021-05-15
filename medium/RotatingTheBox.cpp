class Solution {
   public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();     // 1
        int m = box[0].size();  // 3
        vector<vector<char>> auxa(m, vector<char>(n));
        int r = 0, c = 0;

        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                auxa[r][c] = box[i][j];
                c++;
            }
            r++;
            c = 0;
        }
        for (int i = 0; i < m; i++) {  // rows
            string hr = "";
            for (int j = 0; j < n; j++) {  // cols;
                hr.push_back(auxa[i][j]);
            }
        }
        vector<vector<char>> auxb(m, vector<char>(n));

        for (int col = 0; col < n; col++) {
            int rowa = m - 1;
            int rowb = m - 1;
            int count = 0;
            while (rowa >= 0) {
                while (rowa >= 0 && auxa[rowa][col] != '*') {
                    if (auxa[rowa][col] == '#') count++;
                    rowa--;
                }
                if (rowa >= 0 && auxa[rowa][col] == '*') {
                    auxb[rowa][col] = '*';
                }
                while (count > 0) {
                    auxb[rowb][col] = '#';
                    rowb--;
                    count--;
                }
                while (rowb > rowa) {
                    auxb[rowb][col] = '.';
                    rowb--;
                }
                rowa--;
                rowb = rowa;
            }
        }

        return auxb;
    }
};