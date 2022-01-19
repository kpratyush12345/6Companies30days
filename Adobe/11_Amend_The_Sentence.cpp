// https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1

class Solution
{
public:
    string amendSentence(string s)
    {
        // your code here
        if (isupper(s[0]))
            s[0] = tolower(s[0]);
        string ans = "";
        int i = 0, j = 0;
        while (j < s.length())
        {
            if (isupper(s[j]))
            {
                s[j] = tolower(s[j]);
                ans += s.substr(i, j - i);
                ans += " ";
                i = j;
            }
            j++;
        }
        ans += s.substr(i, j - i);
        return ans;
    }
};