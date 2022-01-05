// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int firstPos = 0, sum = 0, minLength = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                minLength = min(minLength, i - firstPos + 1);
                sum -= nums[firstPos++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};