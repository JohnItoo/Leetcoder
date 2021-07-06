class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> itemFrequencyMap;
        for(int i = 0; i < n; i++) {
            itemFrequencyMap[arr[i]]++;
        }
        vector<pair<int, int> > frequencyItemVector;
        
       for(auto item : itemFrequencyMap) {
           frequencyItemVector.push_back({item.second, item.first});
       }
       sort(frequencyItemVector.rbegin(), frequencyItemVector.rend());
       int value = n;
        int ans = 0;
        while(value > n/2) {
            value -= frequencyItemVector[ans].first;
            ans++;
        }
        return ans;
    }
};