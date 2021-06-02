class Solution {
   public:
    string st1, st2, st3;
    bool isInter(int left, int right, int idx, int s1idx, int s2idx, int pick,
                 map<pair<int, int>, bool>& leftMP,
                 map<pair<int, int>, bool>& rightMP) {
        int n = st1.size();
        int m = st2.size();
        int o = st3.size();
        if (idx == o) {  // s3idx;
            int diff = abs(left - right);
            return diff <= 1 && s1idx == n && s2idx == m;
        }
        bool valid = false;
        if (pick) {
            if (leftMP.find({s1idx, idx}) != leftMP.end())
                return leftMP[{s1idx, idx}];
            for (int i = s1idx; i < n; i++) {
                string s1sub = st1.substr(s1idx, i - s1idx + 1);
                int s3sublen = min(o - idx, i - s1idx + 1);
                string s3sub = st3.substr(idx, s3sublen);
                if (s1sub != s3sub) continue;
                valid |= isInter(left + 1, right, idx + s3sublen, i + 1, s2idx,
                                 0, leftMP, rightMP);
            }
            leftMP[{s1idx, idx}] = valid;
        } else {
            if (rightMP.find({s2idx, idx}) != rightMP.end())
                return rightMP[{s2idx, idx}];
            for (int i = s2idx; i < m; i++) {
                string s2sub = st2.substr(s2idx, i - s2idx + 1);
                int s3sublen = min(o - idx, i - s2idx + 1);
                string s3sub = st3.substr(idx, s3sublen);
                if (s2sub != s3sub) continue;
                valid |= isInter(left, right + 1, idx + s3sublen, s1idx, i + 1,
                                 1, leftMP, rightMP);
            }
            rightMP[{s2idx, idx}] = valid;
        }
        return valid;
    }
    bool isInterleave(string s1, string s2, string s3) {
        st1 = s1;
        st2 = s2;
        st3 = s3;

        int subsleft = 0, subsright = 0;
        int i = 0, j = 0, k = 0;
        bool valid = true;
        map<pair<int, int>, bool> left, right;
        return isInter(0, 0, 0, 0, 0, 0, left, right) ||
               isInter(0, 0, 0, 0, 0, 1, left, right);
    }
};