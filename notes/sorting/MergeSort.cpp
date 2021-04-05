vector<int> merge(vector<int>& left, vector<int>& rt) {
    int n = left.size();
    int m = rt.size();
    vector<int> res(n + m);
    int i = 0, k = 0, j = 0;
    while (i < n || j < m) {
        if (j == m || (i < n && left[i] < rt[j])) {
            res[k++] = left[i++];
        } else {
            res[k++] = rt[j++];
        }
    }
    return res;
}
vector<int> sort(vector<int>& A) {
    int n = A.size();
    if (n < 2) return A;
    int mid = n / 2;
    vector<int> left, rt;
    for (int i = 0; i < mid; i++) {
        left.push_back(A[i]);
    }
    for (int i = mid; i < n; i++) {
        rt.push_back(A[i]);
    }
    left = sort(left);
    rt = sort(rt);
    return merge(left, rt);
}