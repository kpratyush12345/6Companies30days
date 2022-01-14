// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    void dfs(int u, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int>> &bridges, int &timer)
    {
        disc[u] = low[u] = timer++;

        for (int v : adj[u])
        {
            if (disc[v] == -1)
            {
                parent[v] = u;
                dfs(v, adj, disc, low, parent, bridges, timer);
                low[u] = min(low[v], low[u]);

                if (low[v] > disc[u])
                    bridges.push_back({u, v});
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<pair<int, int>> bridges;
        int timer = 0;
        for (int i = 0; i < V; i++)
            if (parent[i] == -1)
                dfs(i, adj, disc, low, parent, bridges, timer);

        for (auto i : bridges)
        {
            if ((i.first == c and i.second == d) or (i.first == d and i.second == c))
                return 1;
        }
        return 0;
    }
};