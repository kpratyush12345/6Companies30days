// https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart

class Solution
{
public:
    int height(int N)
    {
        // code here
        int i = 1;
        int res = 1;
        while (res <= N)
        {
            res += i + 1;
            i += 1;
        }
        return i - 1;
    }
};