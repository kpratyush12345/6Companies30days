// https://practice.geeksforgeeks.org/problems/implement-atoi/1/

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        // Your code here
        bool neg = false;
        int n = str.length();
        int i = 0;
        if (str[0] == '-')
        {
            neg = true;
            i = 1;
            n -= 1;
        }
        int ans = 0;
        while (i < str.length())
        {
            if (str[i] >= 48 and str[i] <= 57)
                ans = ans * 10 + (str[i] - '0');
            else
                return -1;
            i++;
        }
        if (neg)
            ans = -1 * ans;
        return ans;
    }
};