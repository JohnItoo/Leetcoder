class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int INF = 1e9 + 8;
        vector<int> sum(n + 1, INF);
        sum[0] = 0;
        sum[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            if (i - 1 >= 0)
            {
                sum[i] = min(sum[i - 1] + cost[i - 1], sum[i]);
            }
            if (i - 2 >= 0)
            {
                sum[i] = min(sum[i - 2] + cost[i - 2], sum[i]);
            }
        }
        return sum[n];
    }
};