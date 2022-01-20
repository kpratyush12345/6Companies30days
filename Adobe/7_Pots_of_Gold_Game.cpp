// https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#

class Solution
{
public:
    int dp[1001][1001];
    int solve(int i, int j, vector<int> &a)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int x = a[i] + min(solve(i + 2, j, a), solve(i + 1, j - 1, a));
        int y = a[j] + min(solve(i, j - 2, a), solve(i + 1, j - 1, a));
        return dp[i][j] = max(x, y);
    }
    int maxCoins(vector<int> &A, int n)
    {
        // Write your code here
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, A);
    }
};