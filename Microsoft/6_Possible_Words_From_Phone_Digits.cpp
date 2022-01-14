// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#

class Solution
{
public:
    vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        if (N == 0)
            return {};
        vector<string> result;
        result.push_back("");

        for (int i = 0; i < N; i++)
        {
            vector<string> tmp;
            for (auto candidate : pad[a[i]])
            {
                for (auto s : result)
                {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        sort(result.begin(), result.end());
        return result;
    }
};