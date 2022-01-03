class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n+1, 0);
        vector<int> trusted(n+1, 0);
        
        int size = trust.size();
        
        for(int i = 0; i < size; i++) {
            trusts[trust[i][1]]++;
            trusted[trust[i][0]]++;
        }
        
        vector<int> eligible;
        
        for(int i = 1; i <= n; i++) {
            if(trusted[i] == 0 && trusts[i] == n-1) {
                eligible.emplace_back(i);
            }
        }
        if(eligible.size() <= 0 || eligible.size() > 1) {
            return -1;
        }
        return eligible[0];
    }
};