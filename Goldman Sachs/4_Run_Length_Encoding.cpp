// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#

string encode(string src)
{
    // Your code here
    int i = 0, j = 0;
    int n = src.length();
    string ans = "";
    while (j < n - 1)
    {
        if (src[j] != src[j + 1])
        {
            ans += src[j];
            ans += to_string(j - i + 1);
            i = j + 1;
        }
        else if (j == n - 2 && src[j] == src[j + 1])
        {
            ans += src[j];
            ans += to_string(j - i + 2);
        }
        j++;
    }
    if (src[n - 1] != src[n - 2])
    {
        ans += src[n - 1];
        ans += to_string(1);
    }
    return ans;
}