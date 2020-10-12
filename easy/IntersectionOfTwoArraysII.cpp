class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<bool> dn(n2, false);
        vector<int> result;
        if (n1 == 0 || n2 == 0) return result;


        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (dn[j]) continue;
                if (nums1[i] != nums2[j]) continue;
                dn[j] = true;
                result.push_back(nums1[i]);
                break;
            }
        }
        return result;

    }
};