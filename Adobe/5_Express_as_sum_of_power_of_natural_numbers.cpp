// https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#

class Solution
{
public:
    long long numOfWays(int n, int x)
    {
        // code here
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = dp[1] = 1;

        int maxLimit = pow(n, 1.0 / x);

        for (int i = 2; i <= maxLimit; i++)
        {
            int curr = pow(i, x);
            for (int j = n; j >= curr; j--)
            {
                dp[j] += dp[j - curr] % 1000000007;
            }
        }

        return dp[n] % 1000000007;
    }
};