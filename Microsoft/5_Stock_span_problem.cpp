// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        vector<int> a;
        int ans[n];
        ans[0] = 1;
        a.push_back(1);
        for (int i = 1; i < n; i++)
        {
            int counter = 1;
            while ((i - counter) >= 0 && price[i] >= price[i - counter])
            {
                counter += ans[i - counter];
            }
            ans[i] = counter;
            a.push_back(ans[i]);
        }
        return a;
    }
};