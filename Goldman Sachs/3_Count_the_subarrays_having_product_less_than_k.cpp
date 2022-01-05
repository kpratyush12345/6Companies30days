// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        long long p = 1;
        int res = 0;
        for (int start = 0, end = 0; end < n; end++)
        {
            p *= a[end];
            while (start < end && p >= k)
                p /= a[start++];
            if (p < k)
            {
                int len = end - start + 1;
                res += len;
            }
        }
        return res;
    }
};