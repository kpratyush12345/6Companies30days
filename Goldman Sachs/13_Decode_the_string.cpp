// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution
{
public:
    string decodeString(string &s, int &i)
    {
        string result;
        while (i < s.length() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.length() && isdigit(s[i]))
                    k = k * 10 + s[i++] - '0';
                i++; // for opening bracket
                string r = decodeString(s, i);
                while (k-- > 0)
                    result += r;
                i++; // for closing bracket
            }
            else
                result += s[i++];
        }
        return result;
    }

    string decodedString(string s)
    {
        // code here
        int i = 0;
        return decodeString(s, i);
    }
};