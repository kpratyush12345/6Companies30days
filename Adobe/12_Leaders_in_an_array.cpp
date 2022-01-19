// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> ans;
        int cur_mx = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            cur_mx = max(cur_mx, a[i]);
            if (cur_mx == a[i])
                ans.push_back(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
