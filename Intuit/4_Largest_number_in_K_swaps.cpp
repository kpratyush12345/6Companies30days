//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#

class Solution
{
public:
    //Function to find the largest number after k swaps.
    void solve(string str, int k, string &max, int ctr)
    {
        if (k == 0)
            return;

        int n = str.length();
        char maxm = str[ctr];

        for (int j = ctr + 1; j < n; j++)
        {
            if (maxm < str[j])
                maxm = str[j];
        }

        if (maxm != str[ctr])
            --k;

        for (int j = n - 1; j >= ctr; j--)
        {
            if (str[j] == maxm)
            {
                swap(str[ctr], str[j]);
                if (str.compare(max) > 0)
                    max = str;

                solve(str, k, max, ctr + 1);
                swap(str[ctr], str[j]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        // code here.
        string max = str;
        solve(str, k, max, 0);
        return max;
    }
};