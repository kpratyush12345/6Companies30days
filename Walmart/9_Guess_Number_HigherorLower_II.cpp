// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; ++len)
        {
            for (int begin = 0; begin <= n - len; ++begin)
            {
                int end = begin + len;
                for (int i = begin; i < end; ++i)
                {
                    int numPicked = i + 1;
                    if (i == begin)
                    {
                        dp[begin][end] = numPicked + dp[begin + 1][end];
                    }
                    else
                    {
                        dp[begin][end] = min(dp[begin][end], max(dp[begin][i], dp[i + 1][end]) + numPicked);
                    }
                }
            }
        }
        return dp[0][n];
    }
};