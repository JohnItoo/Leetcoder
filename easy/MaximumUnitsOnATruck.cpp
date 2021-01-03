class Solution {
public:
   static bool comp(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         int n = boxTypes.size();
        vector<pair<int, int>> b(n);
        for(int i = 0; i < n; i++) {
            b[i] = make_pair(boxTypes[i][0], boxTypes[i][1]);
        }
        sort(b.begin(), b.end(), comp);
        int i = 0;
        int ans = 0;
        while(i < n && truckSize - b[i].first >= 0) {
            truckSize -= b[i].first;
            ans += b[i].first * b[i].second;
            i++;
        }
        if(i < n) ans += b[i].second * truckSize;
        return ans;
    }
};