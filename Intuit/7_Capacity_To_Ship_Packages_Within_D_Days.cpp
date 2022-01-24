//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution
{
public:
    int solve(int cap, vector<int> &weights)
    {
        int d = 1;
        int sum = 0;
        for (auto x : weights)
        {
            if (sum + x > cap)
            {
                d++;
                sum = x;
            }
            else
                sum += x;
        }
        return d;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int mx = *max_element(weights.begin(), weights.end());
        int low = mx;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
            sum += weights[i];
        int high = sum;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (solve(mid, weights) <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};