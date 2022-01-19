// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i = 0, j = 0;
        int cur_sum = arr[0];
        while (i < n && j < n)
        {
            if (cur_sum < s)
            {
                j++;
                cur_sum += arr[j];
            }
            else if (cur_sum > s)
            {
                cur_sum -= arr[i];
                i++;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {-1};
    }
};