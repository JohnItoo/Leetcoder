class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idmn = min_element(nums.begin() , nums.end()) - nums.begin();
        int idmx = max_element(nums.begin() , nums.end()) - nums.begin();
        int n = nums.size();
        int a = n - min(idmn, idmx);
        int b = max(idmx, idmn) + 1;
        int c = min(idmx, idmn) + 1  + n - max(idmn, idmx);
        return min(a, min(b, c));
    }
};