class Solution {
    vector<int> arr;
    vector<vector<int>> result;
    vector<int> curr;

    int n = 0;

private: void backtrack(int i) {
        if (i == n) {
            result.push_back(curr);
            return;
        }

        backtrack(i + 1);
        curr.push_back(arr[i]);
        backtrack(i + 1);
        curr.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        arr = nums;
        n = nums.size();

        backtrack(0);
        return result;

    }
};