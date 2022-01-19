// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1)
            return 0;

        sum = sum / 2;
        int t[N + 1][sum + 1];
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = 0;
                else if (j == 0)
                    t[i][j] = 1;
                else if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[N][sum];
    }
};