// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

class Solution
{
public:
    bool isCyclic(int N, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == N)
            return false;
        return true;
    }

    bool isPossible(int N, vector<pair<int, int>> &pre)
    {
        // Code here
        vector<int> adj[N + 1];
        for (int i = 0; i < pre.size(); i++)
        {
            adj[pre[i].first].push_back(pre[i].second);
            // adj[pre[i].second].push_back(pre[i].first);
        }

        return !isCyclic(N, adj);
    }
};