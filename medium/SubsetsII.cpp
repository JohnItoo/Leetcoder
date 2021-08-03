class Solution {
public:
    void recurse(int i, string& curr, set<string>& res,
                 vector<int>& nums, vector<int>& subsets
                 ,vector<vector<int> >& result) {
        int n = nums.size();
        if(i == n) {
           auto it = res.insert(curr);
           if(it.second) {
               result.push_back(subsets);
           }
            return;
        }
        recurse(i+1, curr, res, nums, subsets, result);
        string next = curr + to_string(nums[i]) + "*";
        subsets.push_back(nums[i]);
        recurse(i+1, next, res, nums, subsets,result);
        subsets.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        string curr = "";
        sort(nums.begin(), nums.end());
        set<string> res;
        vector< vector<int> > result;
        vector<int> subsets;

        recurse(0, curr, res, nums,subsets, result );
      
        return result;
        
    }
};