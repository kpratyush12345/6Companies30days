// https://leetcode.com/problems/path-with-maximum-probability/

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> to(n);
        for (int i = 0; i < edges.size(); i++)
        {
            to[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            to[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        vector<double> Prob(n, 0);
        queue<int> Q;
        Q.push(start);
        Prob[start] = 1;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (auto child : to[node])
            {
                int nxt = child.first;
                double p = child.second;
                if (Prob[nxt] < Prob[node] * p)
                    Prob[nxt] = Prob[node] * p, Q.push(nxt);
            }
        }
        return Prob[end];
    }
};