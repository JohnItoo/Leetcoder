class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        if (n == 0) return;
        int left = 0;
        int right = 0;
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        while (left < n && right < n) {
            while (right < n) {
                if (nums[right] == 0) zeros++;
                else if (nums[right] == 1) ones++;
                else twos++;
                right++;
            }
            while (left < n) {
                while (zeros) {
                    nums[left++] = 0;
                    zeros--;
                }
                while (ones) {
                    nums[left++] = 1;
                    ones--;
                }
                while (twos) {
                    nums[left++] = 2;
                    twos--;
                }
            }
        }

        return;
    }
};