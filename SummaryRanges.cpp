class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        if (n == 0) return result;

        if (n == 1) {
            result.push_back(to_string(nums[0]));
            return result;
        }

        int i = 0;
        int j = 1;
        while (j < n) {
            if (nums[j] == nums[j - 1] + 1) {
                j++;
            } else {
                if (j - i > 1) {
                    result.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
                    i = j;
                    j = i + 1;
                } else {
                    result.push_back(to_string(nums[i]));
                    i = j;
                    j = i + 1;
                }
            }
        }

        if (j - i > 1) {
            result.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            i = j;
            j = i + 1;
        } else {
            result.push_back(to_string(nums[i]));
            i = j + 1;
            j = i + 1;
        }
        return result;
    }
};