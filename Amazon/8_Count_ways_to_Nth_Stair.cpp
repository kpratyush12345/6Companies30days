// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/

class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n)
    {
        // your code here
        vector<long long> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + 1;
        }
        return dp[n];
    }
};