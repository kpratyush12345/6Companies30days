// https://leetcode.com/problems/longest-mountain-in-array/

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        int max_length = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
            {
                int start_root = i;
                int end_root = i;
                while (start_root > 0 && arr[start_root] > arr[start_root - 1])
                {
                    start_root--;
                }
                while (end_root < n - 1 && arr[end_root] > arr[end_root + 1])
                {
                    end_root++;
                }
                max_length = max(max_length, (end_root - start_root + 1));
                i = end_root;
            }
        }
        return max_length;
    }
};