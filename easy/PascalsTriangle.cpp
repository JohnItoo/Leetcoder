class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> one(1, 1);
        res.push_back(one);
        if(numRows == 1) {
            return res;
        }
        vector<int> two(2, 1);
        res.push_back(two);
        while(res.size() < numRows) {
            vector<int> curr = res[res.size() -1];
            vector<int> here;
            here.push_back(curr[0]);
            for(int i = 1; i < curr.size(); i++) {
                here.push_back(curr[i-1] + curr[i]);
            }
            here.push_back(curr[curr.size()-1]);
            res.push_back(here);
        }
        return res;
    }
};