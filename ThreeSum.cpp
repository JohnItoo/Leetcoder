class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<pair<int, int> > validx;
        set<tuple<int, int, int> > res;
        set<int> types;
        vector<vector<int> > ans;
        map<int, int> ct;
        for (int i = 0; i < n; i++) {
            validx.insert(make_pair(nums[i], i));
            ct[nums[i]]++;
            types.insert(nums[i]);
        }
        auto gt = ct.find(0);

        if (types.size() == 1) {

            vector<vector<int> > temp(1, vector<int>(3, 0));
            if (gt != ct.end() && gt->second >= 3) {
                return temp;
            } else if (gt != ct.end() && gt->second < 3) {
                return ans;
            } else return ans;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sm = nums[i] + nums[j];
                int rm = -sm;
                pair<int, int> need = make_pair(rm, -1);
                auto k = validx.upper_bound(need);
                while (k != validx.end()) {
                    pair<int, int> want = *k;
                    if (want.first != rm) break;
                    if (want.second != i && want.second != j) {
                        int arr[3] = {nums[i], nums[j], nums[want.second]};
                        sort(arr, arr + 3);
                        tuple<int, int, int> tp = make_tuple(arr[0], arr[1], arr[2]);
                        res.insert(tp);
                        break;
                    }
                    ++k;
                }

            }
        }

        auto it = res.begin();
        while (it != res.end()) {
            int x, y, z = 0;
            tuple<int, int, int> curtuple = *it;
            tie(x, y, z) = curtuple;
            vector<int> pref;
            pref.push_back(x);
            pref.push_back(y);
            pref.push_back(z);
            ans.push_back(pref);
            ++it;
        }
        return ans;
    }
};