// https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution
{
public:
    void matchPairs(char nuts[], char bolts[], int n)
    {
        // code here
        unordered_map<char, int> hash;

        // creating a hashmap for nuts
        for (int i = 0; i < n; i++)
            hash[nuts[i]] = i;

        // searching for nuts for each bolt in hash map
        for (int i = 0; i < n; i++)
        {
            if (hash.find(bolts[i]) != hash.end())
                nuts[i] = bolts[i];
        }
        sort(nuts, nuts + n);
        sort(bolts, bolts + n);
    }
};