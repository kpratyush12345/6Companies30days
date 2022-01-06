// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#

class Solution
{
public:
    int maxProfit(int k, int n, int prices[])
    {
        // code here
        if (n == 0)
            return 0;
        int dp[k + 1][n];
        memset(dp, 0, sizeof(dp));
        for (int t = 1; t <= k; t++)
        {
            int mx = INT_MIN;
            for (int d = 1; d < n; d++)
            {
                if (dp[t - 1][d - 1] - prices[d - 1] > mx)
                    mx = dp[t - 1][d - 1] - prices[d - 1];
                if (mx + prices[d] > dp[t][d - 1])
                    dp[t][d] = mx + prices[d];
                else
                    dp[t][d] = dp[t][d - 1];
            }
        }
        return dp[k][n - 1];
    }
};