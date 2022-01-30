// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart#

class Solution
{
public:
// You need to complete this fucntion
#define mod 1000000007
    long long power(int N, int R)
    {
        // Your code here
        if (R == 0)
            return 1;
        if (R == 1)
            return N;
        long long ans = power(N, R / 2) % 1000000007;
        ans = (ans * ans) % 1000000007;
        if (R % 2 == 0)
            return ans % 1000000007;
        return (ans * N) % 1000000007;
    }
};