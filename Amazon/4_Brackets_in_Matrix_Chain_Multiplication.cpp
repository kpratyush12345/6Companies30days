// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

class Solution
{
private:
    string ans = "";

public:
    void ok(int i, int j, int n, int *bracket, char &name)
    {
        if (i == j)
        {
            ans += name++;
            return;
        }

        ans += "(";
        ok(i, *((bracket + i * n) + j), n, bracket, name);

        ok(*((bracket + i * n) + j) + 1, j, n, bracket, name);
        ans += ")";
    }

    string matrixChainOrder(int p[], int n)
    {
        // code here
        int m[n][n];
        int bracket[n][n];

        for (int i = 1; i < n; i++)
            m[i][i] = 0;

        for (int L = 2; L < n; L++)
        {
            for (int i = 1; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        char name = 'A';
        ok(1, n - 1, n, (int *)bracket, name);
        return ans;
    }
};