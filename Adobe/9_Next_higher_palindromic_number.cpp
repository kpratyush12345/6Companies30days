// https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/#

class Solution
{
public:
    string nextPalin(string s)
    {
        // complete the function here
        int n = s.size();
        if (n <= 3)
            return "-1";
        string half = s.substr(0, n / 2);
        if (next_permutation(half.begin(), half.end()))
        {
            string ans = half;
            if (n & 1)
            {
                ans += s[n / 2];
            }
            reverse(half.begin(), half.end());
            ans += half;
            return ans;
        }
        return "-1";
    }
};