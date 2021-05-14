class Solution {
   public:
    bool isValidString(string s) {
        int n = s.length();
        if (s[0] == '0' && n == 1) {
            return true;
        }
        if (s[0] == '0' && s[1] == '.' && s[n - 1] != '0') return true;

        bool point = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '.') point = true;
        }

        if (s[0] != '0' && !point) return true;

        if (point && s[n - 1] != '0' && s[0] != '0') return true;

        return false;
    }

    vector<string> ambiguousCoordinates(string s) {
        int n = s.length();
        vector<string> result;

        string temp = s.substr(1, n - 2);

        s = temp;
        n = s.length();

        for (int len = 1; len < n; len++) {
            string left = s.substr(0, len);
            string right = s.substr(len, n - len);

            vector<string> validLefts;
            if (isValidString(left)) validLefts.push_back(left);

            for (int point = 1; point < len; point++) {
                string lls = left.substr(0, point);
                lls.push_back('.');
                string lrt = left.substr(point, len - point);
                string curr = lls + lrt;
                if (isValidString(curr)) validLefts.push_back(curr);
            }

            vector<string> validRights;
            if (isValidString(right)) validRights.push_back(right);

            int rlen = n - len;

            for (int point = 1; point < rlen; point++) {
                string rls = right.substr(0, point);
                rls.push_back('.');
                string rrt = right.substr(point, rlen - point);
                string curr = rls + rrt;
                if (isValidString(curr)) validRights.push_back(curr);
            }

            int lenRights = validRights.size();
            int lenLefts = validLefts.size();

            if (lenRights == 0 || lenLefts == 0) continue;

            for (int i = 0; i < lenLefts; i++) {
                for (int j = 0; j < lenRights; j++) {
                    string ans =
                        "(" + validLefts[i] + ", " + validRights[j] + ")";
                    result.push_back(ans);
                }
            }
        }
        return result;
    }
};