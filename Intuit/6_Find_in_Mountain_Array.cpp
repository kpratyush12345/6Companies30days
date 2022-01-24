//https://leetcode.com/problems/find-in-mountain-array/

class Solution
{
public:
    int bs(MountainArray &nums, int left, int n, int target)
    {
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int val = nums.get(mid);
            if (val == target)
                return mid;
            else if (target > val)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int rbs(MountainArray &nums, int left, int n, int target)
    {
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int val = nums.get(mid);
            if (val == target)
                return mid;
            else if (target > val)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &nums)
    {
        int left = 0;
        int n = nums.length();
        int right = n - 1;
        int piviot = 0;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums.get(mid) < nums.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        piviot = left;
        if (nums.get(piviot) == target)
            return piviot;
        int k = bs(nums, 0, piviot, target);
        if (k != -1)
            return k;
        k = rbs(nums, piviot + 1, n, target);
        if (k != -1)
            return k;
        return -1;
    }
};