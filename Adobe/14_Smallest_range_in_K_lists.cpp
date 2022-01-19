// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/#

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        // code here
        vector<pair<int, int>> a;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                a.push_back({KSortedArray[i][j], i});
        }
        sort(a.begin(), a.end());

        int mn = INT_MAX;
        int d = k;
        vector<int> mp(d, 0);
        int total = 0;
        int j = 0;
        pair<int, int> ans;
        for (int i = 0; i < a.size(); i++)
        {
            mp[a[i].second]++;
            if (mp[a[i].second] == 1)
                total++;
            if (total == d)
            {
                if (a[i].first - a[j].first + 1 < mn)
                {
                    mn = a[i].first - a[j].first + 1;
                    ans = {a[j].first, a[i].first};
                }
            }
            if (total == d)
            {
                while (total == d)
                {
                    if (mp[a[j].second] > 1)
                        mp[a[j].second]--, j++;
                    else
                        break;
                }
                if (a[i].first - a[j].first + 1 < mn)
                {
                    mn = a[i].first - a[j].first + 1;
                    ans = {a[j].first, a[i].first};
                }
            }
        }
        return ans;
    }
};