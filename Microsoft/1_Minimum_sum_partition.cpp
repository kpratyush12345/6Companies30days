// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        bool T[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                T[i][j] = false;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            T[i][0] = true;
            for (int j = 1; i > 0 && j <= sum; j++)
            {
                T[i][j] = T[i - 1][j];

                if (arr[i - 1] <= j)
                {
                    T[i][j] |= T[i - 1][j - arr[i - 1]];
                }
            }
        }

        int j = sum / 2;
        while (j >= 0 && !T[n][j])
        {
            j--;
        }
        return sum - 2 * j;
    }
};