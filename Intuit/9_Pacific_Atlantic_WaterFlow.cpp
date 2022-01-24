//https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution
{
public:
    int n, m;
    void dfs(int i, int j, int prev, vector<vector<bool>> &ocean, vector<vector<int>> &h)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || h[i][j] < prev || ocean[i][j])
            return;
        prev = h[i][j];
        ocean[i][j] = true;
        dfs(i + 1, j, prev, ocean, h);
        dfs(i - 1, j, prev, ocean, h);
        dfs(i, j + 1, prev, ocean, h);
        dfs(i, j - 1, prev, ocean, h);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        vector<vector<int>> ans;
        n = h.size(), m = h[0].size();
        vector<vector<bool>> at(n, vector<bool>(m, false)), pac(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, -1, pac, h);
            dfs(i, m - 1, -1, at, h);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(0, i, -1, pac, h);
            dfs(n - 1, i, -1, at, h);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (at[i][j] && pac[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};