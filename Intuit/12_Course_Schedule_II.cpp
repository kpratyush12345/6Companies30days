//https://leetcode.com/problems/course-schedule-ii/

class Solution
{
public:
    bool checkCycle(int src, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsvis)
    {
        vis[src] = 1;
        dfsvis[src] = 1;
        for (auto i : adj[src])
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsvis))
                    return true;
            }
            else if (dfsvis[i])
                return true;
        }
        dfsvis[src] = 0;
        return false;
    }

    void dfs(int src, vector<vector<int>> &adj, vector<int> &visited, stack<int> &s)
    {
        visited[src] = 1;
        for (auto i : adj[src])
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsvis))
                    return ans;
            }
        }

        stack<int> s;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};