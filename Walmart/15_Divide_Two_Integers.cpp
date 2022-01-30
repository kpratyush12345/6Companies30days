// https://leetcode.com/problems/divide-two-integers/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        long long dd = abs(dividend), dv = abs(divisor);
        long long high = INT_MAX;
        high += 5;
        long long low = 0;
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (dv * mid > dd)
                high = mid;
            else
                low = mid + 1;
        }
        int ans;
        if (low - 1 > INT_MAX)
            ans = INT_MAX;
        else
            ans = low - 1;
        return signbit(divisor) == signbit(dividend) ? ans : -1 * ans;
    }
};