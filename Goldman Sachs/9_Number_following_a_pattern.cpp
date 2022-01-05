// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        // code here
        stack<int> st;
        int num = 1;
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            st.push(num);
            num++;
            if (s[i] == 'I')
            {
                while (!st.empty())
                {
                    str += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while (!st.empty())
        {
            str += to_string(st.top());
            st.pop();
        }
        return str;
    }
};