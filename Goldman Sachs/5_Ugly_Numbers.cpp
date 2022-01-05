// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        // code here
        ull c2 = 0, c3 = 0, c5 = 0;
        vector<ull> dp(n + 1);
        dp[0] = 1;
        for (ull i = 1; i <= n; i++)
        {
            dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
            if (2 * dp[c2] == dp[i])
                c2++;
            if (3 * dp[c3] == dp[i])
                c3++;
            if (5 * dp[c5] == dp[i])
                c5++;
        }
        return dp[n - 1];
    }
};