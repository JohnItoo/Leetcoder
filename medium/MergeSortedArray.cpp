class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> aux;
        swap(n, m);
        while(i < n || j < m) {
            if(i < n &&  (j >= m || nums1[i] < nums2[j])) {
                aux.push_back(nums1[i++]);
            } else {
                aux.push_back(nums2[j++]);
            }
        }
        for(int i =0; i < n+m; i++) {
            nums1[i] = aux[i];
        }
    }
};