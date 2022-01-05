// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        sort(arr, arr + n);
        int x;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                x = arr[i];
                break;
            }
        }
        int y;
        for (int i = 1; i < n + 1; i++)
        {
            if (binary_search(arr, arr + n, i))
            {
                continue;
            }
            else
            {
                y = i;
            }
        }
        int *ans = new int[2];
        ans[0] = x;
        ans[1] = y;

        return ans;
    }
};
