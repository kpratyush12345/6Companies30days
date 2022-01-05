// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        unordered_map<int, int> mp;
        for (auto val : nums)
        {
            int rem = val % k;
            mp[rem]++;
        }
        for (auto val : nums)
        {
            int rem = val % k;
            if (rem == 0)
            {
                if (mp[rem] % 2 == 1)
                    return false;
            }
            else if (2 * rem == k)
            {
                if (mp[rem] % 2 == 1)
                    return false;
            }
            else
            {
                if (mp[rem] != mp[k - rem])
                    return false;
            }
        }
        return true;
    }
};