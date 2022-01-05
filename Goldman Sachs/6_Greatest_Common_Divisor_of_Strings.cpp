// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1.length() > str2.length())
            swap(str1, str2);
        for (int k = str1.size(); k >= 1; k--)
        {
            if (str1.size() % k != 0)
                continue;
            if (str2.size() % k != 0)
                continue;
            string s = str1.substr(0, k);

            int flag = 1;
            for (int i = 0; i < str1.size(); i += k)
            {
                if (str1.substr(i, k) != s)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;

            for (int i = 0; i < str2.size(); i += k)
            {
                if (str2.substr(i, k) != s)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;
            return s;
        }
        return "";
    }
};