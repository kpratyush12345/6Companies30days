// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#

class Solution
{
public:
    void genrate_paranthesis(string current, int open, int close, int n, vector<string> &v)
    {
        if (current.length() == 2 * n)
        {
            v.push_back(current);
        }
        if (open < n)
            genrate_paranthesis(current + "(", open + 1, close, n, v);
        if (close < open)
            genrate_paranthesis(current + ")", open, close + 1, n, v);
    }

    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        vector<string> v;
        genrate_paranthesis("(", 1, 0, n, v);
        return v;
    }
};