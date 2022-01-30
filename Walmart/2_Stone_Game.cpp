// https://leetcode.com/problems/stone-game/

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += piles[i];
        }
        int dp[n + 1][n + 1];
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = piles[i];
                }
                else if (gap == 1)
                {
                    dp[i][j] = max(piles[i], piles[j]);
                }
                else
                {
                    int val1 = piles[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    int val2 = piles[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        int opp = sum - dp[0][n - 1];
        return (opp < dp[0][n - 1]) ? true : false;
    }
};