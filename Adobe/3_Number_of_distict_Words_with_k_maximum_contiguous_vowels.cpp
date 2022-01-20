// https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/#

class Solution
{
public:
    long long int t[1001][1001];
    long long int solve(int N, int K, int cnt)
    {
        if (N == 0)
            return 1;
        if (t[N][cnt] != -1)
            return t[N][cnt];
        if (cnt < K)
            return t[N][cnt] = (21 * solve(N - 1, K, 0) + 5 * solve(N - 1, K, cnt + 1)) % 1000000007;
        if (cnt == K)
            return t[N][cnt] = 21 * solve(N - 1, K, 0) % 1000000007;
    }
    int kvowelwords(int N, int K)
    {
        // Write Your Code here
        memset(t, -1, sizeof(t));
        return solve(N, K, 0) % 1000000007;
    }
};
