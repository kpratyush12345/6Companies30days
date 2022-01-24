//https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int locMax = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dir : dirs)
            {
                int nx = dir.first + cur.first;
                int ny = dir.second + cur.second;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = grid[cur.first][cur.second] + 1;
                    locMax = max(grid[nx][ny], locMax);
                }
            }
        }
        return (locMax > 0 ? locMax - 1 : -1);
    }
};