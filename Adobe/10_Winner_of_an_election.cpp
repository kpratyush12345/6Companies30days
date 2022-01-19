// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#

class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int mx = 0;
        string vote, name;
        for (auto i : mp)
        {
            if (i.second > mx)
            {
                mx = i.second;
                vote = to_string(i.second);
                name = i.first;
            }
        }
        return {name, vote};
    }
};