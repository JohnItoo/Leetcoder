class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        multiset<int> st;
        cout << idx << endl;
        vector<int> result;

        int left = idx - 1;
        int right = idx;

        while (k) {
            if (left < 0 || (right < arr.size() &&
                             abs(arr[right] - x) < abs(arr[left] - x))) {
                st.insert(arr[right++]);
            } else {
                st.insert(arr[left--]);
            }
            k--;
        }

        for (int item : st) {
            result.push_back(item);
        }
        return result;
    }
};