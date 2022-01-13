// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

class Solution
{
public:
    // Function to find unit area of the largest region of 1s.
    int findLen(int i, int j, int n, int m, vector<vector<int>> &v, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0 || visited[i][j] == 1)
            return 0;
        visited[i][j] = 1;
        return 1 + findLen(i, j - 1, n, m, v, visited) + findLen(i + 1, j - 1, n, m, v, visited) + findLen(i + 1, j, n, m, v, visited) + findLen(i + 1, j + 1, n, m, v, visited) + findLen(i, j + 1, n, m, v, visited) + findLen(i - 1, j + 1, n, m, v, visited) + findLen(i - 1, j, n, m, v, visited) + findLen(i - 1, j - 1, n, m, v, visited);
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), area = INT_MIN;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                area = max(area, findLen(i, j, n, m, grid, vis));
            }
        }
        return area;
    }
};