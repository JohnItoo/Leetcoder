class Solution
{
public:
    vector<int> a;
    int total = 0;
    int dp[20500][300];
    bool inTemp(int sum, int i)
    {
        if (i == a.size())
        {
            return dp[sum][i] = dp[sum][i] == 1 || (sum * 2) == total;
        }
        if (dp[sum][i] != -1)
            return dp[sum][i];

        return dp[sum][i] = inTemp(sum + a[i], i + 1) || inTemp(sum, i + 1);
    }
    bool canPartition(vector<int> &nums)
    {
        a = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        memset(dp, -1, sizeof dp);
        return inTemp(0, 0);
    }
};