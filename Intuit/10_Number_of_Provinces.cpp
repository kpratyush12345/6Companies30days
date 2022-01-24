//https://leetcode.com/problems/number-of-provinces/

class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &vis, int i)
    {
        vis[i] = true;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j] == 1 && !vis[j])
            {
                dfs(isConnected, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), ans = 0;
        if (n == 0)
            return 0;

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(isConnected, vis, i);
            }
        }
        return ans;
    }
};