// https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/#

class Solution
{
public:
    int minSteps(int n)
    {
        // code here
        vector<int> ans;

        int sum = 0;
        int i;

        int sign = (n >= 0 ? 1 : -1);
        n = abs(n);

        for (i = 1; sum < n; i++)
        {
            ans.push_back(sign * i);
            sum += i;
        }

        if (sum > sign * n)
        {
            if (i % 2)
            {
                sum -= n;
                if (sum % 2)
                {
                    ans.push_back(sign * i);
                    sum += i++;
                }
                ans[(sum / 2) - 1] *= -1;
            }
            else
            {
                sum -= n;
                if (sum % 2)
                {
                    sum--;
                    ans.push_back(sign * i);
                    ans.push_back(sign * -1 * (i + 1));
                }
                ans[(sum / 2) - 1] *= -1;
            }
        }
        return ans.size();
    }
};