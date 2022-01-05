// https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

class Solution
{
public:
    int CountWays(string s)
    {
        // Code here
        if (s.length() == 0)
            return -1;
        if (s[0] == '0')
            return 0;
        int n = s.length();
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == '0' && s[i] == '0')
                dp[i] = 0;
            else if (s[i - 1] == '0' && s[i] != '0')
                dp[i] = dp[i - 1] % 1000000007;
            else if (s[i - 1] != '0' && s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    dp[i] = (i >= 2 ? dp[i - 2] : 1) % 1000000007;
                }
                else
                {
                    dp[i] = 0;
                }
            }
            else
            {
                string str = s.substr(i - 1, 2);
                int x = stoi(str);
                if (x <= 26)
                {
                    dp[i] = dp[i - 1] % 1000000007 + (i >= 2 ? dp[i - 2] : 1) % 1000000007;
                }
                else
                {
                    dp[i] = dp[i - 1] % 1000000007;
                }
            }
        }
        return dp[n - 1] % 1000000007;
    }
};