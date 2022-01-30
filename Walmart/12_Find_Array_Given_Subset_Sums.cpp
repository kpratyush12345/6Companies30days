// https://leetcode.com/problems/find-array-given-subset-sums/

class Solution
{
public:
    vector<int> recoverArray(int n, vector<int> &sums)
    {
        multiset<int> ms(sums.begin(), sums.end()), t1, t2;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int d = *next(ms.begin()) - *ms.begin();
            for (; !ms.empty();)
            {
                auto t = *ms.begin();
                t1.insert(t);
                t2.insert(t + d);
                ms.erase(ms.begin());
                ms.erase(ms.find(t + d));
            }
            if (t1.count(0))
            {
                swap(ms, t1);
                ans[i] = d;
            }
            else
            {
                swap(ms, t2);
                ans[i] = -d;
            }
            t1.clear(), t2.clear();
        }
        return ans;
    }
};