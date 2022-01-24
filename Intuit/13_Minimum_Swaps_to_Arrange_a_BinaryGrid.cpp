//https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        vector<int> t;
        for (int i = 0; i < grid.size(); i++)
        {
            int count = 0;
            for (int j = grid[i].size() - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            t.push_back(count);
        }

        int ans = 0;
        for (int i = 0; i < t.size(); i++)
        {
            int k = i;
            int req = grid.size() - i - 1;
            while (k < grid.size() && t[k] < req)
            {
                k++;
            }
            if (k == grid.size())
                return -1;
            ans = ans + k - i;

            while (k > i)
            {
                t[k] = t[k - 1];
                k--;
            }
        }

        return ans;
    }
};