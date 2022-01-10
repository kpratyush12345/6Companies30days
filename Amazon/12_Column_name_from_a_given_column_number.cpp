// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

class Solution
{
public:
    string colName(long long int n)
    {
        // your code here
        string res;
        char tmp;
        while (n)
        {
            n -= 1;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
    }
};