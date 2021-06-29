class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long maxOdd = 0, maxEven = 0;
        for(auto& num : nums) {
            long long newMaxEven = max(maxEven, maxOdd - num);
             maxOdd = max(maxOdd, maxEven + num);
            maxEven = newMaxEven;
        }
        return max(maxOdd, maxEven);
    }
};