// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        vector<int> vis(26, 0);
        string ans = "";
        vector<char> v;
        int n = A.length();
        for (int i = 0; i < n; i++)
        {
            if (!vis[A[i] - 'a'])
            {
                v.push_back(A[i]);
            }
            vis[A[i] - 'a']++;
            int f = 0;
            int m = v.size();
            for (int j = 0; j < m; j++)
            {
                if (vis[v[j] - 'a'] == 1)
                {
                    ans += v[j];
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                ans += '#';
        }
        return ans;
    }
};