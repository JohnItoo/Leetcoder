class FindSumPairs {
   public:
    unordered_map<int, int> fq;  // nums1
    map<int, int> hr;            // nums2
    vector<int> nd;
    vector<int> num;  // nums1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        for (int i = 0; i < n1; i++) {
            fq[nums1[i]]++;
        }
        int n = nums2.size();
        num = nums1;
        for (int i = 0; i < n; i++) {
            hr[nums2[i]]++;
        }

        nd = nums2;
    }

    void add(int index, int val) {
        int curr = nd[index];
        hr[curr]--;
        nd[index] += val;
        hr[nd[index]]++;
    }

    int count(int tot) {
        int n = nd.size();
        int ans = 0;
        for (int i : num) {
            if (hr.count(tot - i)) {
                ans += hr[tot - i];
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */